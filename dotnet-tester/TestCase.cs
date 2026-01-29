using System;
using System.Text;

namespace DotnetTester
{
    public class TestCase : ITestCase
    {
        private int rows;
        private int columns;
        private List<List<int>> grid;
        private List<(int, int, int)> queriesList = new();

        public TestCase()
        {
            this.rows = Helpers.GenerateRandomInt(1, 6);
            this.columns = Helpers.GenerateRandomInt(1, 6);

            // Initial grid is always all equal to 10
            this.grid = new List<List<int>>();
            for (int i = 0; i < rows; i++)
            {
                var row = new List<int>();
                for (int j = 0; j < columns; j++)
                {
                    row.Add(10);
                }
                grid.Add(row);
            }

            for (int i=0;i<100;i++)
            {
                int x = Helpers.GenerateRandomInt(1, rows + 1);
                int y = Helpers.GenerateRandomInt(1, columns + 1);
                int reduceBy = Helpers.GenerateRandomInt(1, 5);
                queriesList.Add((x, y, reduceBy));
            }
        }

        public string GenerateInput()
        {
            StringBuilder input = new();
            input.AppendLine($"1");
            input.AppendLine($"{rows} {columns}");
            foreach (var row in grid)
            {
                input.AppendLine(string.Join(' ', row));
            }
            input.AppendLine($"{queriesList.Count}");
            foreach (var (x, y, reduceBy) in queriesList)
            {
                input.AppendLine($"{x} {y} {reduceBy}");
            }

            return input.ToString();
        }

        public int BruteForceGrid(List<List<int>> grid)
        {
            int steps = 0;
            int coveredCount = 0;
            List<List<bool>> covered = new List<List<bool>>();
            for (int i = 0; i < rows; i++)
            {
                covered.Add([.. new bool[columns]]);
            }

            while (coveredCount < rows * columns)
            {
                // Find the global minimum value
                int minValue = int.MaxValue;
                int minX = 0, minY = 0;
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < columns; j++)
                    {
                        if (!covered[i][j] && grid[i][j] < minValue)
                        {
                            minValue = grid[i][j];
                            minX = i;
                            minY = j;
                        }
                    }
                }

                // Mark one cell with the minimum value as covered
                covered[minX][minY] = true;
                coveredCount++;
                steps++;

                // Now we do a BFS to cover adjacent cells with same or higher value
                Queue<(int, int)> queue = new();
                queue.Enqueue((minX, minY));
                while (queue.Count > 0)
                {
                    var (x, y) = queue.Dequeue();
                    var directions = new (int, int)[] { (1, 0), (-1, 0), (0, 1), (0, -1) };
                    foreach (var (dx, dy) in directions)
                    {
                        int newX = x + dx;
                        int newY = y + dy;
                        if (newX >= 0 && newX < rows && newY >= 0 && newY < columns &&
                            !covered[newX][newY] && grid[newX][newY] >= grid[x][y])
                        {
                            covered[newX][newY] = true;
                            coveredCount++;
                            queue.Enqueue((newX, newY));
                        }
                    }
                }
            }

            return steps;
        }

        public bool CheckOutput(string output)
        {
            var reader = new StringReader(output);
            var scanner = new FastScanner(reader);

            // We'll read queriesList.Count + 1 integers and brute-force the operations
            int expected = BruteForceGrid(grid);
            int result = scanner.NextInt();

            if (expected != result)
            {
                return false;
            }

            // Now we apply the reduceBy operation in the grid, read another and compare
            foreach (var (x, y, reduceBy) in queriesList)
            {
                grid[x - 1][y - 1] -= reduceBy;
                int newResult = scanner.NextInt();
                int newExpected = BruteForceGrid(grid);
                if (newExpected != newResult)
                {
                    return false;
                }
            }

            return true;
        }
    }
}