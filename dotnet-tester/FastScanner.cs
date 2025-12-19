#nullable enable

namespace DotnetTester
{
    public class FastScanner
    {
        private readonly TextReader reader;
        private string[] tokens = Array.Empty<string>();
        private int index = 0;

    public FastScanner(TextReader reader)
    {
        this.reader = reader;
    }

    public string Next()
    {
        while (index >= tokens.Length)
        {
            string? line = reader.ReadLine();
            if (line == null)
                throw new InvalidOperationException("No more input");

            tokens = line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
            index = 0;
        }
        return tokens[index++];
    }

        public int NextInt() => int.Parse(Next());
        public long NextLong() => long.Parse(Next());
        public double NextDouble() => double.Parse(Next());
    }
}
