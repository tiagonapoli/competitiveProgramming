#include "bits/stdc++.h"
using namespace std;
#ifdef DEBUG
	const bool debug = 1;
#else
	const bool debug = 0;
#endif

#define prin(...) if(debug) logger(#__VA_ARGS__, __VA_ARGS__)
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define sepd() if(debug) cout << endl
#define sep() printf("\n");

template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
	cout << "\n";
}

#define For(i,a,b) for(int i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 100100

char res[100][100];

int main () {

	int firstW, lastW;
	int t = nxt();
	while(t--) {
		int n = nxt();
		string s;
		cin >> s;

		int winCount = 0;
		for(int i=0;i<n;i++) {
			if(s[i] == '2') winCount++;
		}

		if(winCount > 0 && winCount <= 2) {
			printf("NO\n");
			goto finish;
		}

		printf("YES\n");

		firstW = -1;
		lastW = -1;
		for(int i=0;i<n;i++) {
			res[i][i] = 'X';

			for(int j=i+1;j<n;j++) {
				if(s[i] == '1' && s[j] == '1') {
					res[i][j] = '=';
					res[j][i] = '=';
				} else if(s[i] == '1' && s[j] == '2') {
					res[i][j] = '+';
					res[j][i] = '-';
				} else if(s[i] == '2' && s[j] == '1') {
					res[i][j] = '-';
					res[j][i] = '+';
				} else {
					res[j][i] = '+';
					res[i][j] = '-';
				}
			}
		}

		for(int i=0;i<n;i++) {
			if(s[i] == '2') {
				firstW = i;
				break;
			}
		}

		for(int i=n-1;i>=0;i--) {
			if(s[i] == '2') {
				lastW = i;
				break;
			}
		}

		if(winCount > 0) {
			res[firstW][lastW] = '+';
			res[lastW][firstW] = '-';
		}


		prin(n);

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				printf("%c", res[i][j]);
			}
			sep();
		}
		sep();

		finish:;

	}

	return 0;

}



