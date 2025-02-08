#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
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
#define sep() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 1001000

ll dp[N][2];
ll a[N];
ll r1,r2,r3,d;

int main () {

	int n;
	cin >> n;

	FOR(i,0,n) {
		dp[i][0] = dp[i][1] = 1e18;
	}

	cin >> r1 >> r2 >> r3 >> d;

	FOR(i,0,n) {
		scanf("%lld", &a[i]);
	}

	dp[0][0] = a[0] * r1 + r3;
	dp[0][1] = min(a[0] * r1 + r1, r2);

	ll res = -1;
	FOR(i,0,n-1) {
		ll &now0 = dp[i][0];
		ll &now1 = dp[i][1];
		ll &nxt0 = dp[i+1][0];
		ll &nxt1 = dp[i+1][1];
		
		if(debug) {
			printf("%d,0 = %lld\n", i, now0);
			printf("%d,1 = %lld\n", i, now1);
		}

		// 0 -> 0
		// doesnt have to finish $now
		nxt0 = min(nxt0, now0 + d + a[i+1] * r1 + r3);

		// 1 -> 0
		// has to finish $now
		nxt0 = min(nxt0, now1 + d + a[i+1] * r1 + r3 + 2*d + r1);
		nxt0 = min(nxt0, now1 + d + a[i+1] * r1 + r1 + 2*d + 2*r1);
		nxt0 = min(nxt0, now1 + d + r2 + 2*d + 2*r1);

		// 0 -> 1
		// doesnt have to finish $now
		nxt1 = min(nxt1, now0 + d + a[i+1] * r1 + r1);
		nxt1 = min(nxt1, now0 + d + r2);
		
		// 1 -> 1
		// has to finish $now
		nxt1 = min(nxt1, now1 + d + a[i+1] * r1 + r1 + 2*d + r1);
		nxt1 = min(nxt1, now1 + d + r2 + 2*d + r1);

		if(i == n-2) {
			res = now1 + d + a[i+1]*r1 + r3 + d + r1;
			if(debug) {
				printf("%d,0 = %lld\n", i+1, nxt0);
				printf("%d,1 = %lld\n", i+1, nxt1);
				printf("Res n-1 %lld\n", res);
			}

		}
	}


	res = min(res, dp[n-1][0]);
	printf("%lld\n", res);

	return 0;

}



