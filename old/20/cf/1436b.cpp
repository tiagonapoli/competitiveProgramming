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
#define sepd() if(debug) cout << endl
#define sep() printf("\n");

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 1001

int v[N][N];

vector<int> p;
bool vis[N];

void sieve() {

	for(int i=2;i<N;i++) {
		if(vis[i] == 0) p.pb(i);
		for(int j=i;j<N;j+=i) {
			vis[j] = 1;
		}
	}
}

int main () {

	int t = nxt();
	sieve();

	while(t--) {
		int n = nxt();

		For(i,0,n) {
			For(j,0,n) {
				v[i][j] = 1;
			}
		}

		int s = n-1;
		int pos = lower_bound(all(p), n) - p.begin();
		int res = p[pos];
		prin(res);
		
		while(binary_search(all(p), res - s)) {
			pos++;
			res = p[pos];
			prin(pos);
			prin(res);
		}

		For(i,0,n) {
			v[i][i] = res - s;
		}

		For(i,0,n) {
			For(j,0,n) {
				printf("%d ", v[i][j]);
			}
			sep();
		}

	}



	return 0;

}



