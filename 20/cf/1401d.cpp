#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

bool debug = 0;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define separa() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 100100

vector<int> adj[N];
ll ch[N];
vector<ll> q;
vector<ll> p;

void pre(int u, int ant = -1) {
	ch[u] = 1;
	for(int v : adj[u]) {
		if(v == ant) continue;
		pre(v, u);
		ch[u] += ch[v];
	}
}

void calc(int u, int ant, ll qtd) {
	ll r = ch[u] * qtd;
	if(u != 1) q.pb(r);
	prin(u);
	prin(ch[u]);
	prin(qtd);
	prin(r);
	separa();
	
	for(int v : adj[u]) {
		if(v == ant) continue;
		calc(v, u, ch[u] - ch[v] + qtd);
	}
}

int main () {

	int t;

	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		q.clear();
		p.clear();
		for(int i=0;i<=n;i++) {
			adj[i].clear();
			ch[i] = 0;
		}

		int a,b;
		for(int i=0;i<n-1;i++) {
			scanf("%d %d", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}

		pre(1);
		calc(1,0,0);

		int m;
		scanf("%d", &m);
		
		p.clear();
		for(int i=0;i<m;i++) {
			scanf("%d", &a);
			p.pb(a);
		}

		while(p.size() < q.size()) p.pb(1);
	
		sort(p.begin(), p.end());
		sort(q.begin(), q.end());
		
		ll res = 0;
		for(int i=0;i<q.size()-1;i++) {
			res += (p[i] * (q[i] % MOD)) % MOD;
			res %= MOD;
			if(debug) printf("[%d] %lld %lld\n", i, p[i], q[i]);
		}

		ll aux = 1;
		for(int i=q.size()-1;i<p.size();i++) {
			aux *= p[i];
			aux %= MOD;
		}
		res += (q.back() * aux) % MOD;
		res %= MOD;

		cout << res << endl;
	}


	return 0;

}



