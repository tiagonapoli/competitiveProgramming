#include "bits/stdc++.h"
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

#ifdef DEBUG
	const bool debug = 1;
#else
	const bool debug = 0;
#endif

#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define sepd() if(debug) cout << endl
#define sep() printf("\n");

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 2000000

ll fac[N];
ll ifac[N];

ll bpow(ll x, int e) {
	ll r = 1;
	ll aux = x;
	while(e > 0) {
		if(e % 2) {
			r *= aux;
			r %= MOD;
		}
		aux *= aux;
		aux %= MOD;
		e /= 2;
	}

	return r;
}

void init() {
	fac[0] = 1;
	For(i,1,N) fac[i] = (fac[i-1] * i) % MOD;
	ifac[0] = 1;
	For(i,1,N) ifac[i] = (ifac[i-1] * bpow(i, MOD-2)) % MOD; 
}

ll comb(int a, int b) {
	return (((fac[a] * ifac[a-b]) % MOD) * ifac[b]) % MOD;
}

int main () {
	init();
	
	int n = nxt();

	ll res = 0;
	For(i,0,n) {
		ll add = comb(n-1,i);
		res += add;
		res %= MOD;
	}
	

	printf("%lld\n", (MOD + fac[n] - res) % MOD);

	return 0;

}



