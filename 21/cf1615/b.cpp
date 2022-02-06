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
#define N 200100

int v[N][32];

int main () {

	int t = nxt();

	for(int i=0;i<N;i++) {
		for(int j=0;j<20;j++) {
			v[i][j] = v[i-1][j];
			if(i & (1 << j)) {
				v[i][j]++;
			}
		}
	}

	while(t--) {

		int l = nxt();
		int r = nxt();

		int n = r - l + 1;
		int m = n;
		for(int i=0;i<32;i++) {
			int aux = v[r][i] - v[l-1][i];
			m = min(m, n-aux);
		}

		printf("%d\n", m);
	}

	return 0;

}



