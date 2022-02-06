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
#define N 400100

int n;
vector<pii> conditions[N];
int r[N];

bool solve(int u, bool color) {
	r[u] = color;

	prin(u);
	prin(color);

	for(auto x : conditions[u]) {
		prinpar(x);
		bool expected = x.se == 0 ? color : !color;
		if((r[x.fi] == -1 && !solve(x.fi, expected)) || r[x.fi] != expected) {
			return false;
		}
	}

	sepd();

	return true;
}

int main () {

	int t = nxt();

	while(t--) {

		vector<pair<pii, int>> res;
		n = nxt();
		int m = nxt();

		for(int i=0;i<=n;i++) {
			conditions[i].clear();
			r[i] = -1;
		}

		int a, b, c;
		for(int i=0;i<n-1;i++) {
			a = nxt();
			b = nxt();
			c = nxt();

			res.pb({{a, b},c});
			if(c != -1) {
				conditions[a].pb({b,__builtin_popcount(c) % 2} );
				conditions[b].pb({a,__builtin_popcount(c) % 2});
			}
		}

		for(int i=0; i<m;i++) {
			a = nxt();
			b = nxt();
			c = nxt();
			conditions[a].pb({b,c % 2});
			conditions[b].pb({a,c % 2});
		}

		bool hasAns = 1;
		for(int i=1;i<=n;i++) {
			if(r[i] == -1 && !solve(i, 0)) {
				hasAns = false;
				break;
			}
		}

		if(hasAns) {
			printf("YES\n");
			for(auto el : res) {
				a = el.fi.fi;
				b = el.fi.se;
				printf("%d %d %d\n", a, b, el.se == -1 ? (r[a] ^ r[b]) : el.se);
			}
		} else printf("NO\n");	

	}

	return 0;

}



