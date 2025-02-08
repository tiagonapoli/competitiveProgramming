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
#define N 100100

int n;
vector<int> adj[N];
pair<ll, ll> v[N];

bool vis[N];
ll dp[N][2];

void dfs(int u) {
	vis[u] = 1;
	for(int x : adj[u]) {
		if(vis[x] == 1) continue;
		dfs(x);
		dp[u][0] += max(dp[x][0] + abs(v[u].fi - v[x].fi), dp[x][1] + abs(v[u].fi - v[x].se));
		dp[u][1] += max(dp[x][0] + abs(v[u].se - v[x].fi), dp[x][1] + abs(v[u].se - v[x].se));	
	}
}

int main () {

	int t = nxt();

	while(t--) {
		n = nxt();

		for(int i=0;i<=n;i++) {
			adj[i].clear();
			vis[i] = 0;
			dp[i][0] = dp[i][1] = 0;
		}

		for(int i=1;i<=n;i++) {
			v[i].fi = nxt();
			v[i].se = nxt();
		}
		
		int a,b;
		for(int i=0; i<n-1;i++) {
			a = nxt(), b = nxt();
			adj[a].pb(b);
			adj[b].pb(a);	
		}

		dfs(1);
		printf("%lld\n", max(dp[1][0], dp[1][1]));
	}
	


	return 0;

}



