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

const int INF = 1000000000;
int v[N];
int n;

bool brute(int x, int c1, int c2, int c3) {
	for(int i=0;i<=c1;i++) {
		for(int j=0;j<=c2;j++) {
			int aux = (x - i - 2*j);
			if(aux < 0) break;
			if(aux % 3 != 0) continue;
			if(aux / 3 <= c3) return true;
		}
	}

	return false;
}

bool solvable(int c1, int c2, int c3) {
	for(int i=0;i<n;i++) {
		if(brute(v[i], c1, c2, c3) == false) return false;
	}

	return true;
}

int main () {

	int t = nxt();

	while(t--) {
		n = nxt();

		int m = 0;
		for(int i=0;i<n;i++) {
			v[i] = nxt();
			m = max(v[i], m);
		}

		int res = 1000000000;
		for(int i=0;i<=2;i++) {
			for(int j=0;j<=2;j++) {
				for(int k=max(0, m/3-2); k <= m/3; k++) {
					if(debug) printf("%d %d %d - %d\n", i,j,k, solvable(i,j,k));
					if(solvable(i,j,k)) {
						res = min(res, i + j + k);
					}
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;

}



