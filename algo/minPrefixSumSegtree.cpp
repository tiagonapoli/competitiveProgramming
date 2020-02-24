#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

bool debug = 1;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define separa() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 100100

int inf = 10000000;
int sum[4*N], seg[4*N];
int v[N];
int n;

pii query(int i, int j, int l=1, int r=n, int id=1) {
	if(j < l || i > r) return {0, inf};
	if(i <= l && r <= j) return {sum[id], seg[id]};
	int m = (l+r)>>1;
	pii a = query(i,j,l,m,id<<1);
	pii b = query(i,j,m+1,r,id<<1|1);
	return {a.fi+b.fi, min(a.se, a.fi+b.se)}; 
}

inline void pushup(int l, int r, int id) {
	sum[id] = sum[id<<1] + sum[id<<1|1];
	seg[id] = min(seg[id<<1], sum[id<<1] + seg[id<<1|1]);
}

void upd(int pos, int val, int l=1, int r=n, int id=1) {
	if(l == r) {
		sum[id] = seg[id] = v[l] = val;
		return;
	}
	int m = (l+r)>>1;
	if(pos <= m) {
		upd(pos, val, l, m, id<<1);
	} else upd(pos, val, m+1, r, id<<1|1);
	pushup(l,r,id);
}

void build(int l=1, int r=n, int id=1) {
	if(l == r) {
		sum[id] = seg[id] = v[l];
		return;
	}
	int m = (l+r)>>1;
	build(l,m,id<<1);
	build(m+1,r,id<<1|1);
	pushup(l,r,id);
}

void print() {
	pii r;
	for(int i=1;i<=n;i++) {
		r = query(1,i);
		printf("%d[%d] ", r.fi, r.se);
	}
	printf("\n");
}


int main () {

	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &v[i]);
	}

	build();
	print();

	int q, op, a, b, c;
	scanf("%d", &q);
	
	for(int i=0;i<q;i++) {
		scanf("%d %d", &a, &b);
		upd(a,b);
		print();
	}

	return 0;
}



