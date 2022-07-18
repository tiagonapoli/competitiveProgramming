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

const ll MOD = 998244353 ;
const double PI = acos(-1.0);
const double eps = 1e-9;
inline int nxt() { int x; scanf("%d", &x); return x; }
inline ll nxtll() { ll x; scanf("%lld", &x); return x; }
#define N 1000100

ll fpow(ll b, int e) {
	ll res = 1;
	while(e > 0) {
		if(e & 1) res = (res * b) % MOD;
		b = (b * b) % MOD;
		e /= 2;
	}

	return res;
}

ll invf(ll x) { return fpow(x, MOD - 2); }
ll mul(ll a, ll b) { return (a * b) % MOD; }
ll inv[N];

ll querem[N];
ll prob[N];

int main () {

	for(int i=1;i<N;i++) inv[i] = invf(i);
	int n = nxt();
	ll res =0;
	for(int i=0;i<n;i++) {
		int k = nxt();
		for(int j=0;j<k;j++) {
			int item = nxt();
			querem[item]++;
			prob[item] += mul(inv[n], inv[k]);
			prob[item] %= MOD;
		}
	}

	for(int i=0;i<N;i++) {
		res += mul(prob[i], mul(querem[i], inv[n]));
		res %= MOD;
	}

	printf("%lld\n", res);


	return 0;

}



