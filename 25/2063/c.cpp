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
#define N 200100

vector<int> adj[N];
int h[N];
set<tuple<int, int, int>> best;

void dfs(int prev, int u) {
	for(int x : adj[u]) {
		if(x == prev) continue;
		h[x] = h[u] + 1;
		dfs(u, x);
	}
}

int main () {

	int t = nxt();
	while(t--) {
		int n = nxt();
		best.clear();
		for(int i=0;i<n;i++) {
			adj[i].clear();
		}

		for(int i=0;i<n-1;i++) {
			int a = nxt() - 1;
			int b = nxt() - 1;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		if (n == 2) {
			printf("0\n");
			continue;
		}

		h[0] = 0;
		dfs(0, 0);
		for(int i=0;i<n;i++) {
			best.insert({ adj[i].size() - 1, h[i], i });
		}

		int res = 1;
		auto it = best.end();
		it--;
		auto [increase, height, u] = *it;
		best.erase(it);
		
		prin(increase);
		prin(height);
		prin(u);

		res += increase;
		prin(res);
		for(int x : adj[u]) {
			prin(x);
			it = best.find({ adj[x].size() - 1, h[x], x });
			int newVal = get<0>(*it) - 1;
			if(debug) printf("[%d] %d -> %d %d %d\n", x, get<0>(*it), newVal, get<1>(*it), get<2>(*it));
			best.erase(it);
			best.insert({ newVal, h[x], x });
		}

		it = best.end();
		it--;
		if(debug) printf("it: %d %d %d\n", get<0>(*it), get<1>(*it), get<2>(*it));
		res += get<0>(*it);

		printf("%d\n", res);
	}

	return 0;

}

