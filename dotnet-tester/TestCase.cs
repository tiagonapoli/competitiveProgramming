using System;
using System.Text;

namespace DotnetTester
{
    public class TestCase : ITestCase
    {
        private int n;
        private int best;
        private int a;
        private int b;

        public TestCase()
        {
            n = Helpers.GenerateRandomInt(1, 25000);
            best = int.MinValue;
            a = 0;
            b = 0;
            for (int i = 0; i <= n; i++)
            {
                for (int j = i; j <= n; j++)
                {
                    if ((i ^ j) == n && i + j > best)
                    {
                        best = i + j;
                        a = i;
                        b = j;
                    }
                }
            }

            // Console.WriteLine($"Generated n = {n}, best = {best} ({a} + {b})");
        }

        public string GenerateInput()
        {
            StringBuilder input = new();
            input.AppendLine($"1");
            input.AppendLine($"{n} 2");
            return input.ToString();
        }

        public bool CheckOutput(string output)
        {
            var reader = new StringReader(output);
            var scanner = new FastScanner(reader);

            int aa = scanner.NextInt();
            int bb = scanner.NextInt();
            // Console.WriteLine($"Received answer: {aa} + {bb} = {aa + bb}");
            if (aa + bb < best || (aa ^ bb) != n)
            {
                Console.WriteLine($"Wrong answer for {n}: {aa} + {bb} = {aa + bb} - should be {a} + {b} = {best}");
                return false;
            }

            return true;
        }
    }
}