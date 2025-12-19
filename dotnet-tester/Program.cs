using System;
using System.Collections.Concurrent;
using System.Diagnostics;
using System.IO;
using System.Threading;
using System.Threading.Tasks;

namespace DotnetTester
{
    class Program
    {
        static void PrintUsage()
        {
            Console.WriteLine("Usage: MyRunner <path-to-cpp-file> [options]");
            Console.WriteLine("Options:");
            Console.WriteLine("  -n, --runs <count>      Number of runs (default: 1)");
            Console.WriteLine("  -t, --threads <count>   Number of threads (default: 1)");
            Console.WriteLine("  -v, --verbose           Show input and output for each run");
        }

        static bool CompileCpp(string cppPath, string outputPath)
        {
            Console.WriteLine($"Compiling {cppPath}...");

            var process = new Process();
            process.StartInfo.FileName = "g++";
            process.StartInfo.Arguments = $"-Wall -std=c++23 -g -Wshadow -Wextra -Wformat=2 -Wconversion -fsanitize=address,undefined -fno-sanitize-recover -o \"{outputPath}\" \"{cppPath}\"";
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.RedirectStandardOutput = true;
            process.StartInfo.RedirectStandardError = true;
            process.StartInfo.CreateNoWindow = true;

            process.Start();

            string stdout = process.StandardOutput.ReadToEnd();
            string stderr = process.StandardError.ReadToEnd();

            process.WaitForExit();

            if (!string.IsNullOrEmpty(stdout))
            {
                Console.WriteLine(stdout);
            }

            if (!string.IsNullOrEmpty(stderr))
            {
                Console.WriteLine(stderr);
            }

            if (process.ExitCode != 0)
            {
                Console.WriteLine($"Compilation failed with exit code {process.ExitCode}");
                return false;
            }

            Console.WriteLine("Compilation successful.");
            return true;
        }

        static int runCounter = 0;
        static int threadCounter = 0;
        static ThreadLocal<int> threadId = new ThreadLocal<int>(() => Interlocked.Increment(ref threadCounter));
        static ConcurrentDictionary<int, int> threadRunCounts = new ConcurrentDictionary<int, int>();
        static ConcurrentDictionary<int, ConcurrentBag<double>> threadLatencies = new ConcurrentDictionary<int, ConcurrentBag<double>>();

        static (bool success, bool crashed, int exitCode, string input, string output, string error, Exception ex) RunTest(string exePath,
            int runNumber,
            int totalRuns,
            bool verbose)
        {
            var testCase = new TestCase();
            string input = testCase.GenerateInput();

            try
            {
                var process = new Process();
                process.StartInfo.FileName = exePath;
                process.StartInfo.UseShellExecute = false;
                process.StartInfo.RedirectStandardInput = true;
                process.StartInfo.RedirectStandardOutput = true;
                process.StartInfo.RedirectStandardError = true;
                process.StartInfo.CreateNoWindow = true;

                process.Start();

                // Send input to executable
                process.StandardInput.Write(input);
                process.StandardInput.Close();

                string output = process.StandardOutput.ReadToEnd();
                string error = process.StandardError.ReadToEnd();

                process.WaitForExit();

                int exitCode = process.ExitCode;
                bool crashed = exitCode != 0;

                if (crashed)
                {
                    return (false, true, exitCode, input, output, error, null);
                }

                bool success = testCase.CheckOutput(output);
                return (success, false, exitCode, input, output, error, null);
            }
            catch (Exception ex)
            {
                return (false, false, -1, input, null, null, ex);
            }
        }

        static int Main(string[] args)
        {
            if (args.Length < 1)
            {
                PrintUsage();
                return 1;
            }

            string cppPath = args[0];
            int numberOfRuns = 1;
            int numberOfThreads = 1;
            bool verbose = false;

            // Parse arguments
            for (int i = 1; i < args.Length; i++)
            {
                switch (args[i])
                {
                    case "-n":
                    case "--runs":
                        if (i + 1 < args.Length)
                        {
                            numberOfRuns = int.Parse(args[++i]);
                        }
                        break;
                    case "-t":
                    case "--threads":
                        if (i + 1 < args.Length)
                        {
                            numberOfThreads = int.Parse(args[++i]);
                        }
                        break;
                    case "-v":
                    case "--verbose":
                        verbose = true;
                        break;
                }
            }

            if (!File.Exists(cppPath))
            {
                Console.WriteLine("C++ source file not found.");
                return 1;
            }

            // Compile the C++ file to a temp directory
            string tempDir = Path.GetTempPath();
            string exePath = Path.Combine(tempDir, $"dotnet-tester-{Guid.NewGuid()}.out");

            if (!CompileCpp(cppPath, exePath))
            {
                return 1;
            }

            // Setup TestResults folder
            string testResultsDir = Path.Combine(Directory.GetCurrentDirectory(), "TestResults");
            if (Directory.Exists(testResultsDir))
            {
                Directory.Delete(testResultsDir, true);
            }
            Directory.CreateDirectory(testResultsDir);

            var cts = new CancellationTokenSource();
            var failedResult = new ConcurrentBag<(int run, string input, string output, string error, Exception ex)>();
            int completedRuns = 0;

            var options = new ParallelOptions
            {
                MaxDegreeOfParallelism = numberOfThreads,
                CancellationToken = cts.Token
            };

            try
            {
                Parallel.For(0, numberOfRuns, options, (i, state) =>
                {
                    if (state.IsStopped) return;

                    int runNumber = Interlocked.Increment(ref runCounter);
                    var sw = Stopwatch.StartNew();
                    var result = RunTest(exePath, runNumber, numberOfRuns, verbose);
                    sw.Stop();
                    double elapsedMs = sw.Elapsed.TotalMilliseconds;

                    // Record latency for this thread
                    var latencies = threadLatencies.GetOrAdd(threadId.Value, _ => new ConcurrentBag<double>());
                    latencies.Add(elapsedMs);

                    lock (Console.Out)
                    {
                        if (result.ex != null)
                        {
                            Console.WriteLine($"[T{threadId.Value}] Run {runNumber}/{numberOfRuns}: Execution failed - {result.ex.Message}");
                            var guid = Guid.NewGuid();
                            string crashInputPath = Path.Combine(testResultsDir, $"{guid}-CrashInput.txt");
                            File.WriteAllText(crashInputPath, result.input);
                            Console.WriteLine($"Crash input saved to: {crashInputPath}");
                            failedResult.Add((runNumber, result.input, result.output, result.error, result.ex));
                            state.Stop();
                            cts.Cancel();
                            return;
                        }

                        if (result.crashed)
                        {
                            Console.WriteLine($"[T{threadId.Value}] Run {runNumber}/{numberOfRuns}: CRASHED (exit code {result.exitCode})");
                            Console.WriteLine("=== Input ===");
                            Console.WriteLine(result.input);
                            if (!string.IsNullOrEmpty(result.output))
                            {
                                Console.WriteLine("=== Output ===");
                                Console.WriteLine(result.output);
                            }
                            if (!string.IsNullOrEmpty(result.error))
                            {
                                Console.WriteLine("=== Stderr ===");
                                Console.WriteLine(result.error);
                            }
                            var guid = Guid.NewGuid();
                            string crashInputPath = Path.Combine(testResultsDir, $"{guid}-CrashInput.txt");
                            File.WriteAllText(crashInputPath, result.input);
                            Console.WriteLine($"Crash input saved to: {crashInputPath}");
                            if (!string.IsNullOrEmpty(result.output))
                            {
                                string crashOutputPath = Path.Combine(testResultsDir, $"{guid}-CrashOutput.txt");
                                File.WriteAllText(crashOutputPath, result.output);
                                Console.WriteLine($"Crash output saved to: {crashOutputPath}");
                            }
                            failedResult.Add((runNumber, result.input, result.output, result.error, null));
                            state.Stop();
                            cts.Cancel();
                            return;
                        }

                        if (!result.success)
                        {
                            Console.WriteLine($"[T{threadId.Value}] Run {runNumber}/{numberOfRuns}: WRONG OUTPUT");
                            Console.WriteLine("=== Input ===");
                            Console.WriteLine(result.input);
                            Console.WriteLine("=== Output ===");
                            Console.WriteLine(result.output);
                            if (!string.IsNullOrEmpty(result.error))
                            {
                                Console.WriteLine("=== Stderr ===");
                                Console.WriteLine(result.error);
                            }
                            var guid = Guid.NewGuid();
                            string brokenInputPath = Path.Combine(testResultsDir, $"{guid}-BrokenInput.txt");
                            string brokenOutputPath = Path.Combine(testResultsDir, $"{guid}-BrokenOutput.txt");
                            File.WriteAllText(brokenInputPath, result.input);
                            File.WriteAllText(brokenOutputPath, result.output ?? "");
                            Console.WriteLine($"Broken input saved to: {brokenInputPath}");
                            Console.WriteLine($"Broken output saved to: {brokenOutputPath}");
                            failedResult.Add((runNumber, result.input, result.output, result.error, null));
                            state.Stop();
                            cts.Cancel();
                            return;
                        }

                        threadRunCounts.AddOrUpdate(threadId.Value, 1, (_, count) => count + 1);
                        Console.WriteLine($"[T{threadId.Value}] Run {runNumber}/{numberOfRuns}: OK ({elapsedMs:F1}ms)");
                        if (verbose)
                        {
                            Console.WriteLine("=== Input ===");
                            Console.WriteLine(result.input);
                            Console.WriteLine("=== Output ===");
                            Console.WriteLine(result.output);
                            if (!string.IsNullOrEmpty(result.error))
                            {
                                Console.WriteLine("=== Stderr ===");
                                Console.WriteLine(result.error);
                            }
                        }
                        Interlocked.Increment(ref completedRuns);
                    }
                });
            }
            catch (OperationCanceledException)
            {
                // Expected when we cancel due to failure
            }
            finally
            {
                // Clean up the compiled executable
                if (File.Exists(exePath))
                {
                    try
                    {
                        File.Delete(exePath);
                    }
                    catch
                    {
                        // Ignore cleanup errors
                    }
                }
            }

            // Print thread statistics
            Console.WriteLine("\n=== Thread Statistics ===");
            
            static double Percentile(List<double> sorted, int percentile)
            {
                int index = (int)Math.Ceiling(percentile / 100.0 * sorted.Count) - 1;
                return sorted[Math.Max(0, index)];
            }

            var allLatencies = new List<double>();
            foreach (var kvp in threadLatencies.OrderBy(x => x.Key))
            {
                var latencies = kvp.Value.ToList();
                latencies.Sort();
                allLatencies.AddRange(latencies);
                int count = latencies.Count;
                double maxMs = latencies.Max();
                double avgMs = latencies.Average();
                double p90 = Percentile(latencies, 90);
                double p95 = Percentile(latencies, 95);
                double p99 = Percentile(latencies, 99);
                Console.WriteLine($"Thread {kvp.Key}: {count} runs, Avg: {avgMs:F1}ms, P90: {p90:F1}ms, P95: {p95:F1}ms, P99: {p99:F1}ms, Max: {maxMs:F1}ms");
            }

            if (allLatencies.Count > 0)
            {
                allLatencies.Sort();
                double p90 = Percentile(allLatencies, 90);
                double p95 = Percentile(allLatencies, 95);
                double p99 = Percentile(allLatencies, 99);
                Console.WriteLine($"\nOverall: Avg: {allLatencies.Average():F1}ms, P90: {p90:F1}ms, P95: {p95:F1}ms, P99: {p99:F1}ms, Max: {allLatencies.Max():F1}ms");
            }

            if (!failedResult.IsEmpty)
            {
                return 2;
            }

            Console.WriteLine($"\nAll {numberOfRuns} runs passed!");
            return 0;
        }
    }
}
