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
#define N 200100

int v[N];

ll mul(ll a, ll b) {
	return (a * b) % MOD;
}

ll sum(ll a, ll b) {
	return (a + b) % MOD;
}

ll expo(ll b, ll e) {
	ll res = 1;
	while(e > 0) {
		if(e & 1) {
			res *= b;
			res %= MOD;
		}

		e /= 2;
		b *= b;
		b %= MOD;
	}

	return res;
}

ll inv(ll x) {
	return expo(x, MOD - 2);
}


ll fat[N];
ll fatinv[N];
ll comb(int tot, int escolhe) {
	return mul(fat[tot], mul(fatinv[escolhe], fatinv[tot - escolhe]));
}

int main () {

	fat[0] = 1;
	fatinv[0] = 1;
	for(int i=1;i<N;i++) {
		fat[i] = mul(fat[i-1], i);
		fatinv[i] = mul(fatinv[i-1], inv(i));	
	}

	int t = nxt();

	while(t--) {
		int n = nxt();
		
		int less = 0;
		int less1 = 0;
		int bigger = 0;
		
		for(int i=0;i<n;i++) {
			v[i] = nxt();
		}

		sort(v, v+n);

		for(int i=0;i<n;i++) {
			if(v[i] == v[n-1]) bigger++;
			if(v[i] < v[n-2]) less++;
			if(v[i] == v[n-2]) less1++;
		}

		if(bigger != 1) {
			printf("%lld\n", fat[n]);
			continue;
		}

		if(v[n-1] - v[n-2] >= 2) {
			printf("0\n");
			continue;
		}

		prin(less1);

		ll res = 0;
		for(int i=less1;i<n;i++) {
			ll x = mul(fat[n-i-1], mul(comb(less, i - less1), fat[i]));
			prin(x);
			res = sum(x, res);
		}

		printf("%lld\n", (fat[n] - res + 2*MOD) % MOD);
	}

	return 0;

}



