#include "bits/stdc++.h"
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

#ifdef DEBUG
	const bool debug = 1;
#else
	const bool debug = 0;
#endif

#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define sep() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 100100


int main () {

	int t = nxt();
	while(t--) {
		int n = nxt();
		for(int i=0;3*i<=n;i++) {
			for(int j=0;7*j<=n-3*i;j++) {
				int m = n - 3*i - 7*j;
				if(m < 0 || m % 5 != 0) continue;
				printf("%d %d %d\n", i, m/5, j);
				goto fini;
			}
		}
		
		printf("-1\n");
fini:;

	}




	return 0;

}



