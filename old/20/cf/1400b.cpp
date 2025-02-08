#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

bool debug = 0;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define separa() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 100100

ll pa, pb;
ll c1, c2;
ll ca, cb;
bool check(ll b) {
	ll cc1, cc2;
	
	for(ll i=0;i<=b;i++) {
		cc1 = c1 - pb*i;
		cc2 = c2 - pb*(b-i);
		if(cc1 < 0 || cc2 < 0) continue;
		if((cc1 / pa) + (cc2 / pa) >= ca) return 1;
	}

	return 0;
}


int main () {

	int t;

	cin >> t;

	while(t--) {
		cin >> c1 >> c2;
		cin >> ca >> cb;
		cin >> pa >> pb;

		if(pa > pb) {
			swap(ca,cb);
			swap(pa,pb);
		}

		if((c1 / pa) + (c2 / pa) <= ca) {
			printf("%lld\n", (c1/pa) + (c2/pa));
			continue;
		}

		ll hi,lo;
		hi = cb+1;
		lo = 0;
		ll res = ca;
		while(lo < hi) {
			ll mid = (hi+lo)/2;
			prin(lo);
			prin(hi);
			prin(mid);
			if(check(mid)) {
				if(debug) printf("ok\n");
				lo = mid+1;
				res = ca + mid;
			} else {
				if(debug) printf("not\n");
				hi = mid;
			}
			separa();
		}

		printf("%lld\n", res);
		
	}


	return 0;

}



