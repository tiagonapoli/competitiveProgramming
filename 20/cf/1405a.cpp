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
int nxt() { int x; cin >> x; return x; }
#define N 100100


int v[N];
int f[N];
int r[N];

int main () {

	int t = nxt();
	
	while(t--) {
		int n = nxt();
		generate(v,v+n,nxt);
		reverse(v, v+n);
		For(i,0,n) printf("%d ", v[i]);
		printf("\n");
	}

	return 0;

}



