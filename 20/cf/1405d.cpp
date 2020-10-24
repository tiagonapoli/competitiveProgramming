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
int nxt() { int x; cin >> x; return x; }
#define N 100100

vector<int> adj[N];
int dist[N];
int n;
bool vis[N];

void bfs(int x) {
	queue<int> fila;
	For(i,0,n+1) vis[i] = 0;
	fila.push(x);
	vis[x] = 1;
	dist[x] = 0;
	while(!fila.empty()) {
		int now = fila.front();
		fila.pop();
		for(int u : adj[now]) {
			if(!vis[u]) {
				vis[u] = 1;
				fila.push(u);
				dist[u] = dist[now] + 1;
			}
		}
	}
}

int main () {

	int t = nxt();

	while(t--) {
		int a,b,da,db;
		scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
		For(i,0,n+1) adj[i].clear();
		int maxi = 1;
		int diameter = 0;

		int x,y;
		For(i,0,n-1){
			x = nxt(); y = nxt();
			adj[x].pb(y);
			adj[y].pb(x);
		}

		bfs(1);
		For(i,1,n+1) if(dist[maxi] < dist[i]) maxi = i;
		prin(maxi);
		prin(dist[maxi]);
		bfs(maxi);
		For(i,1,n+1) diameter = max(diameter, dist[i]);
		prin(diameter);

		bfs(a);
		if(debug) printf("Initial dist %d\n", dist[b]);

		if(dist[b] <= da || diameter <= 2*da || db <= 2*da) {
			printf("Alice\n");
		} else printf("Bob\n");
	}


	return 0;

}



