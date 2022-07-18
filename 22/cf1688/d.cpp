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
#define N 200100

ll v[N];
ll solve1(ll n, ll k) {
	return n * (2LL*k - n - 1LL) / 2LL;
}

ll solve2(ll k) {
	return k * (k-1LL)/2;
}


int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		int k = nxt();

		int sz = 0;
		ll sum = 0;
		ll best = 0;
		for(int i=0;i<n;i++) {
			v[i] = nxt();
			sum += v[i];
			best = max(best, sum);
			sz++;
			prin(best);
			prin(sum);
			sepd();
			if(sz == k) {
				sum -= v[i-k+1];
				sz--;
			}
			
		}

		if(k >= n) {
			printf("%lld\n", best + solve1(n, k));
			continue;
		}

		printf("%lld\n", best + solve2(k));
	}

	return 0;

}



