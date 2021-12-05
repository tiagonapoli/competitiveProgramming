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

int a[N];
vector<int> adj[N];

int xxorAcum[N];
bool vis[N];
int xxor;
bool res = 0;


void dfs(int u) {
	vis[u] = 1;
	for(int x : adj[u]) {
		if(vis[x] == 0) {
			dfs(x);
			xxorAcum[u] ^= xxorAcum[x];
		}
	}

	xxorAcum[u] ^= a[u];
	prin(u);
	prin(xxorAcum[u]);
	sepd();

	if(u != 1 && xxorAcum[u] == xxor) {
		res = 1;
	}
}

int main () {

	int t = nxt();
	while(t--) {
		int n,k;
		n = nxt();
		k = nxt();

		
		xxor = 0;
		res = 0;

		for(int i=0;i<=n;i++) {
			vis[i] = 0;
			xxorAcum[i] = 0;
			adj[i].clear();
		}

		for(int i=1;i<=n;i++) {
			a[i] = nxt();
			xxor ^= a[i];
		}

		prin(xxor);
		int x,y;
		for(int i=0;i<n-1;i++) {
			x = nxt();
			y = nxt();
			adj[x].pb(y);
			adj[y].pb(x);
		}

		if(xxor == 0) {
			printf("YES\n");
			continue;
		}

		dfs(1);
		if(res) {
			printf("YES\n");
			continue;
		}

		printf("NO\n");


	}

	return 0;

}



