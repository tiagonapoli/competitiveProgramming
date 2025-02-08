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

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 1010

ll bigger, lesser;
ll pos, x;
ll n;

void bb() {
	int lo = 0;
	int hi = n;
	int m;

	while(lo < hi) {
		m = (lo + hi) / 2;
		prin(lo);
		prin(hi);
		prin(m);
		
		if(pos < m) {
			bigger++;
			hi = m;
		} else if(pos > m) {
			lesser++;
			lo = m + 1;
		} else {
			lo = m + 1;
		}
	}

	
	prin(bigger);
	prin(lesser);
}

ll fact[N];
void pre() {
	fact[0]= 1;
	For(i,1,N) {
		fact[i] = fact[i-1] * i;
		fact[i] %= MOD;
	}
}



int main () {

	pre();

	n = nxt();
	x = nxt();
	pos = nxt();

	bb();

	ll big = n - x;
	ll low = x - 1LL;

	if(bigger > big || lesser > low) {
		printf("0\n");
		return 0;
	}

	assert(n-bigger-lesser-1>=0);
	ll res = fact[n-bigger-lesser-1];
	prin(big);
	prin(low);
	prin(res);
	while(bigger > 0) {
		res *= big;
		res %= MOD;
		bigger--;
		big--;
	}

	while(lesser > 0) {
		res *= low;
		res %= MOD;
		lesser--;
		low--;
	}

	printf("%lld\n", res);

	return 0;

}



