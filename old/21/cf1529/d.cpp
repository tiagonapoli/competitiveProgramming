#include "bits/stdc++.h"
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
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
#define sepd() if(debug) cout << endl
#define sep() printf("\n");

const ll MOD = 998244353;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 4001000

ll v[N];
ll d[N];

int main () {

	for(int i=1;i<N;i++) {
		for(int j=i;j<N;j+=i) {
			d[j]++;
		}
	}

	int n = nxt();

	ll sum = 0;
	ll r;
	for(int i=1;i<=n; i++) {
		r = sum + d[i]; 
		r %= MOD;
		sum += r;
		sum %= MOD;
	}

	printf("%lld\n", r);
	sep();

	return 0;

}



