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
#define N 100100

ll lcm(ll a, ll b) {
	return a / __gcd(a,b) * b;
}

ll calc(ll n) {

	ll r = 0;
	r += 2 * ((n + 1)/2);
	r %= MOD;
	ll res = n - (n+1)/2;

	ll a;
	a = 2;
	ll x = 3;

	while(res > 0) {
		if(a % x == 0) {
			x++;
			continue;
		}
		
		prin(res);
		prin(x);
		prin(a);

		ll nxt = lcm(a,x);
		prin(nxt);

		ll add = res - (n/nxt);
		prin(add);
		sepd();

		res -= add;
		r += add * x;
		r %= MOD;
		a = lcm(a,x);
		x++;
	}

	return r;
}


int main () {

	int t = nxt();

	while(t--) {
		ll n;
		cin >> n;
		cout << calc(n) << "\n";
	}

	return 0;

}



