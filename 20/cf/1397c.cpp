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
#define N 100100


ll v[N];

int main () {

	ll n;
	cin >> n;
	for(int i=0;i<n;i++) {
		scanf("%lld", &v[i]);
	}

	if(n == 1) {
		printf("1 1\n%lld\n", -v[0]);
		printf("1 1\n0\n");
		printf("1 1\n0\n");
		return 0;
	}

	printf("1 1\n%lld\n", -v[0]);
	v[0] = 0;
	

	printf("2 %lld\n", n);
	for(ll i=1;i<n;i++) {
		ll x = (-v[i]) * (n-1);
		x %= n;
		ll p = v[i] + (n-1) * x;
		prin(p);
		printf("%lld ", p - v[i]);
		sep();
		v[i] = p;
	}

	printf("\n1 %lld\n", n);
	for(int i=0;i<n;i++) {
		printf("%lld ", -v[i]);	
	}
	printf("\n");
	


	return 0;

}



