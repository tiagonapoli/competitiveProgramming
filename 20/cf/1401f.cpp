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
#define N 300100

bool flip[20];
int n;
int totalN;
ll seg[4*N];


ll query(int a, int b, int l=1, int r=totalN, int id=1, int exp=n, int state = 0) {
	if(a > r || b < l) return 0;
	if(a <= l && b >= r) return seg[id];
	state ^= flip[exp];

	int m = (l + r)/2;
	int ida = id*2;
	int idb = id*2+1;
	if(state) swap(ida, idb);
	return query(a,b,l,m,ida,exp-1,state) + query(a,b,m+1,r,idb,exp-1,state);
}

void upd(int x, int pos, int l=1, int r=totalN, int id=1, int exp=n, int state = 0) {
	if(l == r) {
		seg[id] = x;
		return;
	}

	state ^= flip[exp];

	int m = (l+r)/2;
	int ida = id*2;
	int idb = id*2+1;
	if(state) swap(ida,idb);
	if(pos <= m) {
		upd(x,pos,l,m,ida,exp-1,state);
	} else upd(x,pos,m+1,r,idb,exp-1,state);
	seg[id] = seg[ida] + seg[idb];
}

int main () {

	int q;

	cin >> n >> q;
	totalN = 1 << n;
	assert(totalN < N);

	int x;
	for(int i=1;i<=totalN;i++) {
		scanf("%d", &x);
		upd(x,i);
	}


	int a,b,c;
	FOR(i,0,q) {
		scanf("%d %d", &a, &b);

		if(a == 1) {
			scanf("%d", &c);
			upd(c,b);
		} else if(a == 2) {
			flip[b] ^= 1;
		} else if(a == 3) {
			flip[b] ^= 1;
			flip[b+1] ^= 1;
		} else {
			scanf("%d", &c);
			printf("%lld\n", query(b,c));
		}
	}


	return 0;

}



