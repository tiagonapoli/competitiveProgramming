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
    }
}
