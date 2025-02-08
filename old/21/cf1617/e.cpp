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

int findFather(int x) {
	int k = 0;
	while((1 << k) < x) k++;
	return (1 << k) - x;
}

int n;
vector<int> adj[32 * N];
unordered_map<int, int> father;
map<int, int> indices;
bool isDesiredNode[32 * N];


int cnt;
int d[32 * N];
unordered_map<int, int> dict;
int invDict[32 * N];

pii bfs(int x) {
	queue<int> q;
	for(int i=0;i<=cnt;i++) d[i] = -1;

	d[x] = 0;
	q.push(x);
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for(int u : adj[now]) {
			if(d[u] == -1) {
				d[u] = d[now] + 1;
				q.push(u);
			}
		}
	}

	int maxid = x;
	for(int i=0;i<cnt;i++) {
		if(d[i] > d[maxid] && isDesiredNode[i]) {
			maxid = i;
		}
	}

	return { invDict[maxid], d[maxid] };
}

int mapToDict(int x) {
	if(dict.find(x) == dict.end()) {
		dict[x] = cnt;
		invDict[cnt] = x;
		cnt++;
		assert(cnt < 32 * N);
	}

	return dict[x];
}

int main () {

	n = nxt();

	mapToDict(0);

	int x;
	for(int i=0;i<n;i++) {
		x = nxt();
		isDesiredNode[mapToDict(x)] = 1;
		indices[x] = i + 1;
		while(x != 0) {
			int p = findFather(x);
			father[x] = p;
			x = p;
			prin(x);
		}
		sepd();
	}

	for(auto el : father) {
		int a = mapToDict(el.fi);
		int b = mapToDict(el.se);
		adj[a].pb(b);
		adj[b].pb(a);
	}

	auto el = bfs(dict[0]);
	auto el2 = bfs(dict[el.fi]);
	printf("%d %d %d\n", indices[el.fi], indices[el2.fi], el2.se);

	return 0;

}



