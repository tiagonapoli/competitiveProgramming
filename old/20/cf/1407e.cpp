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
#define N 600100

vector<pii> adj[N];
int c[N];
int dist[N];
int m,n;

void bfs(int x) {
	queue<int> fila;

	For(i,0,n+1) {
		dist[i] = c[i] = -1;
	}

	fila.push(x);
	dist[x] = 0;

	while(!fila.empty()) {
		int now = fila.front();
		fila.pop();
		prin(now);
		prin(dist[now]);
		prin(c[now]);
		for(auto u : adj[now]) {
			if(dist[u.fi] != -1) continue;

			if(c[u.fi] == -1) {
				c[u.fi] = !u.se;
				continue;
			}

			if(u.se == c[u.fi]) {
				dist[u.fi] = dist[now] + 1;
				fila.push(u.fi);
			}

		}
		sep();
	}
}

int main () {

	n = nxt();
	m = nxt();

	int x,y,z;
	For(i,0,m) {
		x = nxt();
		y = nxt();
		z = nxt();
		// reversed edge
		adj[y].pb({x,z});
	}

	bfs(n);
	

	printf("%d\n", dist[1]);
	For(i,1,n+1) {
		printf("%d", c[i] >= 0 ? c[i] : 1);
	}
	printf("\n");

	return 0;

}




