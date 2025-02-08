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
inline ll nxtll() { ll x; scanf("%lld", &x); return x; }
#define N 300100

vector<int> adj[N];
int res[N];
int cnt[N];

void fill(int x, int ant) {
	cnt[x] = 1;
	for(int u : adj[x]) {
		if(u == ant) continue;
		fill(u, x);
		cnt[x] += cnt[u];
	}
}

int solve(int x, int ant) {
	prin(x);
	
	vector<pii> opt;
	for(int u : adj[x]) {
		if(u == ant) continue;
		solve(u, x);
		opt.pb({ res[u], u });
	}

	if(opt.size() == 0) return res[x] = 0;

	if(opt.size() == 1) {
		return res[x] = cnt[opt[0].se] - 1;
	}

	assert(opt.size() == 2);
	return res[x] = max(opt[0].fi + cnt[opt[1].se] - 1, opt[1].fi + cnt[opt[0].se] - 1);
}

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();

		for(int i=0;i<n+1;i++) {
			adj[i].clear();
			res[i] = 0;
		}

		int a,b;
		for(int i=0;i<n-1;i++) {
			scanf("%d %d", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}

		fill(1, -1);
		printf("%d\n", solve(1, -1));

		if(debug) {
			for(int i=1;i<=n;i++) {
				printf("%d: %d\n", i, res[i]);
			}
		}
	}

	return 0;

}



