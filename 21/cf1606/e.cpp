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

const ll MOD = 998244353;
const double PI = acos(-1.0);
const double eps = 1e-9;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 100100

int x;
ll dp[550][550];

ll fastpow(ll x, int e) {
	ll res = 1;
	while(e > 0) {
		if(e & 1) {
			res *= x;
			res %= MOD;
		}

		x *= x;
		x %= MOD;
		e >>=1;
	}

	return res;
}

// only works if MOD is prime
ll modinverse(ll x) { return fastpow(x, MOD - 2); }
ll modmul(ll a, ll b) { return (a * b) % MOD; }
ll modsum(ll a, ll b) { return (a + b) % MOD; }

ll fat[550];
ll invfat[550];

void prepareFactorial(int lim) {
	fat[0] = invfat[0] = 1;
	for(int i=1;i<lim;i++) {
		fat[i] = modmul(fat[i-1], i);
		invfat[i] = modmul(invfat[i-1], modinverse(i));
	}
}

ll combination(int x, int y) {
	return modmul(fat[x], modmul(invfat[y], invfat[x-y]));
}

int main () {

	prepareFactorial(550);

	int n;
	n = nxt();
	x = nxt();

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=x;j++) dp[i][j] = 0;
	}

	dp[n][0] = 1;
	for(int i=n; i>1; i--) {
		for(int d=0; d<x; d++) {
			if(dp[i][d] == 0) continue;
			for(int deaths=0; deaths<=i; deaths++) {
				int nxtdamage = min(d+i-1, x);
				ll inc = modmul(dp[i][d], modmul(combination(i, deaths), fastpow((nxtdamage - d), deaths)));
				if(debug) printf("%d/%d -> %d/%d %lld\n", i, d, i-deaths, nxtdamage, inc);
				dp[i-deaths][nxtdamage] = modsum(inc, dp[i-deaths][nxtdamage]);
			}
		}
	}

	ll res = 0;
	for(int i=0;i<=x;i++) {
		res += dp[0][i];
		res %= MOD;
	}

	printf("%lld\n", res);

	if(debug)
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=x;j++) {
			printf("%2lld ", dp[i][j]);
		}
		printf("\n");
	}

	return 0;
}



