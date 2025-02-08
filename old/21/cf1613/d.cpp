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
#define N 500100

ll dp[N][2];
int v[N];

ll modmul(ll a, ll b) { return (a * b) % MOD; }
ll modsum(ll a, ll b) { return (a + b) % MOD; }


int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		for(int i=0;i<=n;i++) dp[i][0] = dp[i][1] = 0;

		for(int i=0;i<n;i++) {
			int x = nxt();
			if(x == 0) {
				dp[1][0] = 2*dp[1][0] + 1;
			} else {
				dp[x+1][0] = 2 * dp[x+1][0] + dp[x][0];

				if(x != 1) {
					dp[x-1][1] = 2 * dp[x-1][1] + dp[x-1][0];
				} else dp[0][1] = 2 * dp[x-1][1] + 1;
				dp[x-1][1] %= MOD;
			}

			dp[x+1][1] = 2 * dp[x+1][1];
			dp[x+1][0] %= MOD;
			dp[x+1][1] %= MOD;

		}

		ll res = 0;
		for(int i=0;i<=n;i++) {
			res += dp[i][0] + dp[i][1];
			res %= MOD;
		}

		printf("%lld\n", res);
	}

	return 0;

}



