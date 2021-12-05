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

const ll MOD = 	1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 200100

ll mul(ll a, ll b) { return (a * b) % MOD; }

ll pot(ll x, ll e = MOD - 2) {
	ll res = 1;
	ll p = x;
	while(e > 0) {
		if(e % 2 == 1) {
			res *= p;
			res %= MOD;
		}
		
		p *= p;
		p %= MOD;
		e /= 2;
	}

	return res;
}

ll fat[N];
ll invfat[N];

ll escolhe(int a, int b) {
	return mul(invfat[b], mul(fat[a], invfat[a - b]));
}

int main () {

	fat[0] = 1;
	invfat[0] = 1;
	for(int i=1;i<N;i++) {
		fat[i] = mul(fat[i-1], i); 
		invfat[i] = mul(invfat[i-1], pot(i));
	}

	int t = nxt();
	while(t--) {
		ll n = nxt();
		ll k = nxt();

		ll draw = 0;
		int ini = 2;
		if(n % 2 == 1) {
			draw++;
			ini = 1;
		}
		for(int i=ini;i<=n;i+=2) {
			draw += escolhe(n, i);
			draw %= MOD;
		}

		prin(draw);

		ll res = 0;
		ll acum = 1;
		for(int i=0;i<k;i++) {
			if(n % 2 == 0) {
				res += mul(acum, pot(2, (k-i-1) * n));
				prin(res);
				res %= MOD;
			}
			acum = mul(acum, draw);
		}

		prin(res);
		prin(acum);
		res += acum;
		res %= MOD;
		printf("%lld\n", res);
	}

	return 0;

}



