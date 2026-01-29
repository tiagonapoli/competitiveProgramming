using System;
using System.Text;

namespace DotnetTester
{
    public static class Helpers
    {
        /// <summary>
        /// Generates a random binary string of the specified length containing only '0' and '1' characters.
        /// </summary>
        public static string GenerateRandomBinaryString(int length)
        {
            var sb = new StringBuilder(length);
            for (int i = 0; i < length; i++)
            {
                sb.Append(Random.Shared.Next(2));
            }
            return sb.ToString();
        }

        /// <summary>
        /// Generates a random integer within the specified range.
        /// </summary>
        public static int GenerateRandomInt(int minInclusive, int maxExclusive)
        {
            return Random.Shared.Next(minInclusive, maxExclusive);
        }

        /// <summary>
        /// Generates a random grid (2D list) of integers with specified dimensions and value range
        /// </summary>
        public static List<List<int>> GenerateRandomGrid(int rows, int cols, int minValue, int maxValue)
        {
            var grid = new List<List<int>>(rows);
            for (int i = 0; i < rows; i++)
            {
                var row = new List<int>(cols);
                for (int j = 0; j < cols; j++)
                {
                    row.Add(GenerateRandomInt(minValue, maxValue));
                }
                grid.Add(row);
            }
            return grid;
        }
    }
}
