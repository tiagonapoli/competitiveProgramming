#include "bits/stdc++.h"
#define pb push_back
#define fi first
#define se second
using namespace std;

void compile(string fileType, string sourcePath, string execPath) {
	cout << "Compiling " << fileType << endl << sourcePath << endl;
	string command = "g++ -std=c++11 -o " + execPath + " " + sourcePath;
	system(command.c_str());
	cout << "Done!" << endl << endl;
}

void prepare(int argc, char *argv[]) {
	if(argc < 4) {
		printf("Usage ./Tester GeneratorPath SolverPath ProgramToTest [TestMod\n");
		exit(0);
	}

	string generatorPath(argv[1]), solverPath(argv[2]), programPath(argv[3]);
	compile("Input Generator", generatorPath, "./generator.tmp");
	compile("Solver", solverPath, "./solver.tmp");
	compile("Program to Test", programPath, "./program.tmp");
}

void runTest() {
	if(system("./generator.tmp > ./files/input.tmp")) {
    printf("Generator execution failed");
    exit(1);
  }

	if(system("./solver.tmp < ./files/input.tmp > ./files/answer.tmp")) {
    printf("Solver execution failed");
    exit(1);
  }

	if(system("./program.tmp < ./files/input.tmp > ./files/output.tmp")) {
    printf("Target execution failed");
    exit(1);
  }
}

string readFile(string filename) {
	string s;
	FILE *f = fopen(filename.c_str(), "r");
	char c;
	while(fscanf(f, "%c", &c) != EOF) {
		s.pb(c);
	}
	fclose(f);
	return s;
}

bool compareAnswers(int i) {
	string ans, out;
	ans = readFile("./files/answer.tmp");
	out = readFile("./files/output.tmp");
	if(ans != out) {
		printf("Error!\n");
		printf("Test %d\n", i + 1);
		cout << "Answer: " << ans << "\n" << "Output: " << out;
		return 0;
	}
	return 1;
}

int main(int argc, char *argv[]){
	prepare(argc, argv);
	int testMod = 10, tests;
	if(argc >= 5) testMod = atoi(argv[4]);
	printf("How many tests? ");
	cin >> tests;

	for(int i=0;i<tests;i++) {
		if(i % testMod  == 0) printf("T%d\n", i+1);
		runTest();
		if(!compareAnswers(i)) break;
	}
	
	return 0;
}

