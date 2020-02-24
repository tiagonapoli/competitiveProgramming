#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

bool debug = 1;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define separa() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 100100

struct eulerianGraph {

	int n, m;
	int eulerian;
	vector<vector<pii> > adj;
	vector<int> odd;

	eulerianGraph(int n) : n(n), m(0), eulerian(-1) { 
		adj.resize(n+1);
		FOR(i,0,n+1) adj[i] = vector<pii>();
	}

	void addEdge(int a, int b) {
		adj[a].pb({b,m});
		adj[b].pb({a,m});
		m++;
	}

	bool isEulerian() {
		if(eulerian != -1) return eulerian;
		FOR(i,0,n+1) {
			if(adj[i].size() % 2 == 1) {
				odd.pb(i);
				if(odd.size() > 2) return eulerian = 0;
			}
		}
		if(odd.size() == 1) return eulerian = 0;
		return eulerian = isConnected();
	}

	void addPlaceholderEdge() {
		if(odd.size() == 0) return;
		addEdge(odd[0], odd[1]);
	}

	void removePlaceholderEdge() {
		if(odd.size() == 0) return;
		m--;
		adj[odd[0]].pop_back();
		adj[odd[1]].pop_back();
	}

	vector<int> findEuler() {
		if(isEulerian() == 0) return vector<int>();
		addPlaceholderEdge();
		vector<bool> used(m,0);
		vector<int> r, cur(n+1,0);
		int first = 0;
		while(adj[first].size() == 0) first++;
		findEulerRec(first, r, used, cur);
		removePlaceholderEdge();

		if(odd.size() > 0) {
			int v1 = odd[0], v2 = odd[1];
			FOR(i,0,r.size()-1) {
				if((r[i] == v1 && r[i+1] == v2) || (r[i] == v2 && r[i+1] == v1)) {
					vector<int> r2;
					FOR(j,i+1,r.size()) r2.pb(r[j]);
					FOR(j,1,i+1) r2.pb(r[j]);
					r = r2;
					break;
				}
			}
		}
		return r;
	}

	private:
	bool isConnected() {
		vector<bool> vis(n+1,0);
		stack<int> p;
		int first = 0;
		while(adj[first].size() == 0) first++;
		p.push(first);
		vis[first] = 1;
		while(!p.empty()) {
			int u = p.top(); p.pop();
			for(auto v : adj[u]) {
				if(vis[v.fi] == 0) {
					p.push(v.fi);
					vis[v.fi] = 1;
				}
			}
		}
		FOR(i,0,n+1) if(adj[i].size() > 0 && vis[i] == 0) return 0;
		return 1;
	}
	
	void findEulerRec(int v, vector<int> &r, vector<bool> &used, vector<int> &cur) {
		prin(v);
		int &i = cur[v];
		for(;i<adj[v].size();i++) {
			if(used[adj[v][i].se]) continue;
			used[adj[v][i].se] = 1;
			int u = adj[v][i].fi;
			i++;
			findEulerRec(u, r, used, cur);
		}
		r.pb(v);
	}
};

int main () {

	
	return 0;

}



