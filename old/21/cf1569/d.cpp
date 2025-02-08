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
inline pii nxtpii() { pii x; scanf("%d %d", &x.fi, &x.se); return x; }
#define N 300100

int ver[N], hor[N];
pii v[N];
int k;

ll solve(int *lines, int sz) {
	sort(v, v+k);
	int j = 0;
	ll res = 0;
	map<int,int> repeated;
	for(int i=0;i<sz-1;i++) {
		ll cnt = 0;
		while(j<k && v[j].fi == lines[i]) j++;
		while(j<k && v[j].fi < lines[i+1]) {
			repeated[v[j].se]++;
			j++;
			cnt++;
		}

		ll contribution = 0;
		for(auto &el : repeated) {
			prinpar(el);
			contribution -= el.se * (el.se-1) / 2;
		}

		repeated.clear();
		contribution += cnt * (cnt - 1) / 2;
		if(debug) printf("%d->%d: %lld\n", lines[i], lines[i+1], contribution);
		res += contribution;
	}

	return res;
}

int main () {

	int t = nxt();

	while(t--) {
		int n, m;
		cin >> n >> m >> k;
		For(i,0,n) ver[i] = nxt();
		For(i,0,m) hor[i] = nxt();
		For(i,0,k) v[i] = nxtpii();
		ll res = solve(ver, n);
		sepd();
		For(i,0,k) swap(v[i].fi, v[i].se);
		res += solve(hor, m);
		printf("%lld\n", res);
	}

	return 0;
}



