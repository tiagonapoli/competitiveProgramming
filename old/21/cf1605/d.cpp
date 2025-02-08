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

vector<int> adj[N];
vector<int> v[32];
vector<int> c[2];
int att[N];
bool vis[N];

void dfs(int x, bool color = 0) {
	vis[x] = 1;
	c[color].pb(x);
	for(int u : adj[x]) {
		if(vis[u] == 1) continue;
		dfs(u, !color);
	}
}

int main () {

	int t = nxt();

	while(t--) {
		for(int i=0;i<32;i++) {
			v[i].clear();
		}

		int n = nxt();
		for(int i=0;i<=n;i++) {
			vis[i] = 0;
			att[i] = 0;
			adj[i].clear();
			c[0].clear();
			c[1].clear();
		}

		int a,b;
		for(int i=0;i<n-1;i++) {
			a = nxt();
			b = nxt();
			adj[a].pb(b);
			adj[b].pb(a);
		}

		int j=-1;
		for(int i=1;i<=n;i++) {
			if(__builtin_popcount(i) == 1) {
				j++;
			}

			v[j].pb(i);
		}

		for(int i=1;i<=n;i++) {
			if(vis[i] == 0) {
				dfs(i);
			}
		}

		if(c[0].size() > c[1].size()) swap(c[0], c[1]);
		int sz = c[0].size();
		for(int i=0;i<31;i++) {
			bool cur = ((sz & (1 << i)) != 0) ? 0 : 1; 
			while(v[i].size() > 0) {
				att[c[cur].back()] = v[i].back();
				v[i].pop_back();
				c[cur].pop_back();
			}
		}

		for(int i=1;i<=n;i++) {
			printf("%d ", att[i]);
		}
		printf("\n");

	}

	return 0;

}



