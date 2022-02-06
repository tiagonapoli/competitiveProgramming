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
#define N 210100

int h[N];
int p[N];
pii besth[N];
priority_queue<pii> opt;

bool covered[N];
vector<int> adj[N];
ll n;
ll k;

void prep(int u) {
	besth[u] = {h[u], u};
	for(int x : adj[u]) {
		if(x == p[u]) continue;
		p[x] = u;
		h[x] = h[u] + 1;
		prep(x);
		if(besth[u].fi < besth[x].fi) {
			besth[u] = besth[x];
		}
	}
}

int iter(int u) {
	int res = 0;
	while(u != -1 && covered[u] != 1) {
		prin(u);
		res++;
		covered[u] = 1;
		for(int x : adj[u]) {
			if(x == p[u] || covered[x] == 1) continue;
			if(debug) printf("[%d] %d - %d/%d \n", x, besth[x].fi, h[u], besth[x].se);
			besth[x].fi -= h[u];
			opt.push(besth[x]);
		}

		u = p[u];
		sepd();
	}

	return res;
}

ll maximize(ll x) {
	if(x >= n/2) {
		return (n/2) * ((n+1)/2);
	}

	return x * (n - x);
}

ll calc(ll c, ll redColored) {
	ll bMax = n - c;
	return redColored * (n-redColored) - maximize(bMax);
}

int main () {

	n = nxt();
	k = nxt();
	int a, b;
	for(int i=0;i<n-1;i++) {
		a = nxt();
		b = nxt();
		adj[a].pb(b);
		adj[b].pb(a);
	}

	p[1] = -1;
	prep(1);
	opt.push(besth[1]);

	int coveredCnt = 0;
	ll res = calc(coveredCnt, 0);
	int kk = k;
	while(kk > 0) {
		kk--;	

		if(opt.size() > 0) {
			pii el = opt.top(); opt.pop();
			coveredCnt += iter(el.se);
			if(debug) printf("%d / %d\n", el.se, el.fi);
		}

		res = max(res, calc(coveredCnt, k - kk));
		sepd();
	}

	printf("%lld\n", res);
	return 0;
}