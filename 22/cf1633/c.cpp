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
inline int nxtll() { ll x; scanf("%lld", &x); return x; }
#define N 100100

ll ceilInt(ll x, ll y) {
	return (x+y-1LL)/y;
}

bool check(ll h1, ll a1, ll h2, ll a2) {
	if(debug) {
		printf("%lld %lld | %lld %lld\n", h1, a1, h2, a2);
	}

	ll t2 = ceilInt(h1, a2);
	ll t1 = ceilInt(h2, a1);
	prin(t1);
	prin(t2);
	return t1 <= t2;
}

int main () {

	int t = nxt();

	while(t--) {
		ll h1, a1, h2, a2;
		scanf("%lld %lld %lld %lld", &h1, &a1, &h2, &a2);
		ll k = nxt();
		ll w = nxt();
		ll a = nxt();

		for(ll i=0;i<=k;i++) {
			if(check(h1 + a * i, a1 + (k - i) * w, h2, a2)) {
				printf("YES\n");
				goto fim;
			}
		}
		
		printf("NO\n");
		fim:;
	}

	return 0;

}



