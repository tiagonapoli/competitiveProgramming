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
#define N 300100

int inf = 1e9;
int v[N];
int bit[N];
int n;

void upd(int id, int x) {
	while(id < N) {
		bit[id] += x;
		id += id & (-id);
	}
}

void upd_range(int a, int b, int x) {
	upd(a, x);
	upd(b+1, -x);
}

int qry(int id) {
	int res = 0;
	while(id > 0) {
		res += bit[id];
		id -= id & (-id);
	}
	return res;
}

int lb(int lo, int hi, int val) {
	int m;
	int res = -1;
	while(lo < hi) {
		m = (hi+lo)/2;
		prin(lo);
		prin(hi);
		prin(m);
		prin(qry(m));
		if(qry(m) >= val) {
			lo = m+1;
			res = m;
		} else hi = m;
	}

	return res;
}

int main () {

	int q;
	pair<pii, int> qq[N];
	int res[N];

	n = nxt();
	q = nxt();
	generate(v+1,v+n+1,nxt);

	For(i,1,n+1) {
		v[i] = i - v[i];
		if(v[i] < 0) v[i] = inf;
	}

	int a,b;
	For(i,0,q) {
		scanf("%d %d", &a, &b);
		qq[i].fi.se = 1 + a;
		qq[i].fi.fi = n - b;
		qq[i].se = i;
	}

	sort(qq,qq+q);
	
	int p = 0;
	for(int i=1;i<=n && p < q; i++) {
		prin(i);
		prin(v[i]);
		int pos = lb(1, i+1, v[i]);
		prin(pos);

		if(pos != -1) {
			upd_range(1, pos, 1);
		}

		while(p < q && qq[p].fi.fi == i) {
			res[qq[p].se] = qry(qq[p].fi.se);
			if(debug) printf("res %d->%d = %d\n", qq[p].fi.fi, qq[p].fi.se, res[qq[p].se]);
			p++;
		}
	}

	For(i,0,q) printf("%d\n", res[i]);

	return 0;

}



