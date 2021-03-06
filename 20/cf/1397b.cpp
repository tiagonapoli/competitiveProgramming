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
#define N 112345

const ll maxi = 10000000000;
vector<ll> p[N];

void pre() {
	for(ll i=2;i<N;i++) {
		ll res = 1;
		while(res < maxi) {
			p[i].pb(res);
			res *= i;
		}
	}
}

int main () {

	pre();

	int n;
	cin >> n;
	int v[N];
	ll res = 0;
	for(int i=0;i<n;i++) {
		scanf("%d", &v[i]);
		res += abs(v[i] - 1);
	}

	sort(v,v+n);
	for(int i=2;i<112345;i++) {
		ll now = 0;
		if(n > (int) p[i].size()) break;
		for(int j=0;j<n;j++) {
			now += abs(p[i][j] - v[j]);
		}

		assert(now >= 0);
		if(res > now) {
			res = now;
		}
	}

	cout << res << endl;


	return 0;

}



