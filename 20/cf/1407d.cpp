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
int nxt() { int x; scanf("%d", &x); return x; }
#define N 300100

vector<pii> st;
int v[N];
vector<int> adj[N];

bool vis[N];
int dist[N];
int n;
void bfs(int ini) {
	queue<int> fila;
	fill(vis,vis+n,0);
	fila.push(ini);
	dist[ini] = 0;
	vis[ini] = 1;

	while(!fila.empty()) {
		int now = fila.front();
		fila.pop();
		for(int x : adj[now]) {
			if(vis[x] == 0) {
				fila.push(x);
				dist[x] = dist[now] + 1;
				vis[x] = 1;
			}
		}
	}
}

int main () {

	n = nxt();
	generate(v,v+n,nxt);

	// nearest greater/equal to the left	
	For(i,0,n) {
		prin(i);
		while(!st.empty() && st.back().fi < v[i]) {
			st.pop_back();
		}

		if(!st.empty()) {
			prin(st.back().se);
			adj[st.back().se].pb(i);
		}

		st.pb({v[i],i});
	}
	sep();
	st.clear();

	// nearest greater/equal to the right
	for(int i=n-1;i>=0;i--) {
		prin(i);
		while(!st.empty() && st.back().fi < v[i]) {
			st.pop_back();
		}

		if(!st.empty()) {
			prin(st.back().se);
			adj[i].pb(st.back().se);
		}

		st.pb({v[i],i});
	}
	sep();
	st.clear();

	// nearest lesser/equal to the left
	For(i,0,n) {
		prin(i);
		while(!st.empty() && st.back().fi > v[i]) {
			st.pop_back();
		}

		if(!st.empty()) {
			prin(st.back().se);
			adj[st.back().se].pb(i);
		}

		st.pb({v[i],i});
	}
	sep();
	st.clear();

	// nearest lesse/equal to the right
	for(int i=n-1;i>=0;i--) {
		prin(i);
		while(!st.empty() && st.back().fi > v[i]) {
			st.pop_back();
		}

		if(!st.empty()) {
			prin(st.back().se);
			adj[i].pb(st.back().se);
		}

		st.pb({v[i],i});
	}
	sep();

	bfs(0);

	printf("%d\n", dist[n-1]);

	return 0;

}



