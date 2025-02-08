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
#define sep() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 300100

int v[N];


int main () {

	int t = nxt();
	while(t--) {
		int n = nxt();
		int k = nxt();
		generate(v,v+n,nxt);
		sort(v,v+n);
		ll maxi = v[n-1];
		int kk = k;
		for(int i=n-2;i>=0 && k > 0;i--,k--) {
			maxi += v[i];	
		}

		
		if(kk > 0) {
			printf("%lld\n", maxi);
		} else printf("%lld\n", maxi - v[0]);

	}

	return 0;

}



