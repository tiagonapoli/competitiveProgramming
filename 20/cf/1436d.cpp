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
#define N 300100

ll maior[N];
ll qtd[N];
ll soma[N];
ll v[N];
vector<int> adj[N];

void dfs(int x, int ant) {
	for(int y : adj[x]) {
		if(y == ant) continue;
		dfs(y, x);
		maior[x] = max(maior[x], maior[y]);
		qtd[x] += qtd[y];
		soma[x] += soma[y];
	}

	if(adj[x].size() == 1 && x != 1) {
		qtd[x] = 1;
		maior[x] = v[x];
		soma[x] = v[x];
	} else {
		soma[x] += v[x];
		if(maior[x] * qtd[x] < soma[x]) {
			maior[x] = (soma[x]+qtd[x]-1LL)/qtd[x];
		}
	}

	prin(x);
	prin(qtd[x]);
	prin(soma[x]);
	prin(maior[x]);
	sepd();
}

int main () {

	int n = nxt();
	for(int i=2;i<=n;i++) {
		int p = nxt();
		adj[i].pb(p);
		adj[p].pb(i);
	}

	generate(v+1,v+n+1,nxt);
	dfs(1, -1);
	printf("%lld\n", maior[1]);

	return 0;

}



