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
#define N 200100

int v[N];

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		iota(v,v+n,1);
		
		vector<pii> res;
		for(int i=n-1;i>0;i--) {
			res.pb({v[i],v[i-1]});
			v[i-1] = (v[i] + v[i-1] + 1)/2;
		}

		printf("%d\n", v[0]);
		for(auto r : res) printf("%d %d\n", r.fi, r.se);
		sep();
	}


	return 0;

}



