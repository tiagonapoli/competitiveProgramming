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
#define N 100100

map<int, bool> adj[N];
set<int> notSolved;

void traverseComponent(int x) {
	if(debug) printf("%d ", x);
	vector<int> neighbors;
	for(auto el : notSolved) {
		if(adj[x].find(el) != adj[x].end()) continue;
		neighbors.pb(el);
	}

	for(auto el : neighbors) notSolved.erase(el);
	for(auto el : neighbors) traverseComponent(el);
}

int main () {

	int n, m;
	n = nxt();
	m = nxt();

	for(int i=1;i<=n;i++) notSolved.insert(i);

	int a,b;
	for(int i=0;i<m;i++) {
		a = nxt();
		b = nxt();
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	int res = -1;
	for(int i=1;i<=n;i++) {
		if(notSolved.find(i) == notSolved.end()) continue;
		res++;
		notSolved.erase(i);
		traverseComponent(i);
		sepd();
	}

	printf("%d\n", res);


	return 0;

}



