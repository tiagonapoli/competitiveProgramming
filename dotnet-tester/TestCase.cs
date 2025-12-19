using System;
using System.Text;

namespace DotnetTester
{
    public class TestCase : ITestCase
    {
        private int n;
        private string source;
        private string target;

        public TestCase()
        {
            this.n = Helpers.GenerateRandomInt(4, 11);
            this.source = Helpers.GenerateRandomBinaryString(n);
            this.target = Helpers.GenerateRandomBinaryString(n);
        }

        public string GenerateInput()
        {
            StringBuilder input = new();
            input.AppendLine($"1");
            input.AppendLine($"{n}");
            input.AppendLine(source);
            input.AppendLine(target);
            return input.ToString();
        }

        public bool CheckOutput(string output)
        {
            var reader = new StringReader(output);
            var scanner = new FastScanner(reader);

            int k = scanner.NextInt();
            if (k > this.n * 2)
            {
                return false;
            }

            List<(int, int)> operations = new();
            for (int i = 0; i < k; i++)
            {
                int l = scanner.NextInt();
                int r = scanner.NextInt();
                operations.Add((l, r));
            }

            StringBuilder transformed = new StringBuilder(source);
            foreach (var (l, r) in operations)
            {
                for (int i = l - 1; i < r; i++)
                {
                    transformed[i] = transformed[i] == '0' ? '1' : '0';
                }
            }

            return transformed.ToString() == target;
        }
    }
}