namespace DotnetTester
{
    public interface ITestCase
    {
        /// <summary>
        /// Generates input to be passed to the executable
        /// </summary>
        string GenerateInput();

        /// <summary>
        /// Validates the executable output
        /// </summary>
        bool CheckOutput(string output);
    }
}