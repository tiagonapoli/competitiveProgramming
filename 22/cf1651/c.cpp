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
#define pii pair<ll,ll>

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
inline int nxt() { int x; scanf("%d", &x); return x; }
inline ll nxtll() { ll x; scanf("%lld", &x); return x; }
#define N 300100

ll v1[N], v2[N];
int n;

ll connect(pii a, pii b) {
	return abs(a.fi - b.fi);
}

ll min4(ll a, ll b, ll c, ll d) {
	return min(min(a, b), min(c, d));
}

ll solve2(pii a1, pii b1, pii a2, pii b2) {
	return min(
		connect(a1, a2) + connect(b1, b2),
		connect(a1, b2) + connect(a2, b1));
}

ll solve3(pii a1, pii b1, pii a2, pii b2) {
	return min4(
		connect(a1, a2) + b1.se + b2.se,
		connect(a1, b2) + a2.se + b1.se,
		connect(b1, a2) + a1.se + b2.se,
		connect(b1, b2) + a1.se + a2.se);
}

ll solve4(pii a1, pii b1, pii a2, pii b2) {
	return a1.se + a2.se + b1.se + b2.se;
}

pii find(ll x, ll v[]) {
	ll best = 2000000000;
	for(int i=0;i<n;i++) {
		best = min(abs(x - v[i]), best);
	}

	return {x, best};
}

int main () {

	int t  = nxt();
	while(t--) {
		n = nxt();
		for(int i=0;i<n;i++) v1[i] = nxtll();
		for(int i=0;i<n;i++) v2[i] = nxtll();
		
		pii a1, a2, b1, b2;
		a1 = find(v1[0], v2);
		b1 = find(v1[n-1], v2);
		a2 = find(v2[0], v1);
		b2 = find(v2[n-1], v1);

		prin(solve2(a1, b1, a2, b2));
		prin(solve3(a1, b1, a2, b2));
		prin(solve4(a1, b1, a2, b2));

		ll res = solve2(a1, b1, a2, b2);
		res = min(res, solve4(a1, b1, a2, b2));
		res = min(res, solve3(a1, b1, a2, b2));

		printf("%lld\n", res);
	}

	return 0;

}



