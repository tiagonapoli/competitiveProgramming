#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define fr(i,a,b) for(int i =a;i<b;i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll, ll>

bool debug = 1;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define separa() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 100100

template <typename T, typename R> struct flowNet {
	
	int n, m;
	T inf;
	vector<pii> adj[N], parent;
	vector<T> flow, cap;

	flowNet(int n, T inf): n(n), m(0), inf(inf) {
		parent = vector<pii>(n+2, {0,0});
	}

	int addEdge(int a, int b, T c) {
		adj[a].pb({b, m});
		flow.pb(0);
		cap.pb(c);
		adj[b].pb({b, m|1});
		cap.pb(0);
		flow.pb(0);
		m += 2;
	}

	void incFlow(int id, int f) { flow[id] += f; flow[id|1] -= f; }
	int canPass(int id) { return cap[id] - flow[id]; }
	
	T augment(int s, int t) {
		bfs(s);
		if(parent[t].fi == -1) return 0;
		int x = t;
		T pathFlow = inf;
		while(x != s) {
			pathFlow = min(pathFlow, canPass(parent[x].se));
			x = parent[x].fi;
		}

		x = t;
		while(x != s) {
			incFlow(parent[x].se, pathFlow);
			x = parent[x].fi;
		}
		return pathFlow;
	}

	void bfs(int s) {
		queue<int> fila;
		for(int i=0;i<parent.size();i++) parent[i] = {-1,-1};
		fila.push(s);
		while(!fila.empty()) {
			int u = fila.front(); fila.pop();
			for(auto v : adj[u]) {
				if(parent[v.fi].fi == -1 && canPass(v.se) > 0) {
					parent[v.fi] = {u, v.se};
					fila.push(v.fi);
				}
			}
		}
	}

	R maxFlow(int s, int t) {
		R res = 0;
		int improv = augment(s,t);
		while(improv > 0) {
			res += improv;
			improv = augment(s,t);
		}
		return res;
	}
};


int main () {

	int cnt = 0;
	map<char,int> node;
	int m;

	cin >> m;
	char a,b;
	int c;

	vector<tuple<int,int,int> > edge;
	for(int i=0;i<m;i++) {
		cin >> a >> b >> c;
		if(node.find(a) == node.end()) {
			node[a] = cnt++;
		}
		if(node.find(b) == node.end()) {
			node[b] = cnt++;
		}
		edge.pb({node[a], node[b], c});
		edge.pb({node[b], node[a], c});
	}

	flowNet<int,ll> flow(cnt, 1000000);
	for(auto t : edge) {
		flow.addEdge(get<0>(t), get<1>(t), get<2>(t));
	}

	cout << flow.maxFlow(node['A'], node['Z']) << endl;
	

	return 0;

}



