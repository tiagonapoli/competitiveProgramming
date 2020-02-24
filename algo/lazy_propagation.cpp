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
#define N 1000100

// Query min-max - sum range

pii v[4*N];
int lazy[4*N];
int n;

void prop(int id, int l, int r) {
	if(lazy[id] == 0) return;
	int t = lazy[id];
	lazy[id] = 0;
	v[id].fi += t;
	v[id].se += t;
	if(l == r) return;
	lazy[id*2] += t;
	lazy[id*2+1] += t;
}

pii query(int a, int b, int id=1, int l=1, int r=n) {
	prop(id,l,r);
	if(b < l || a > r) return {2*N,-2*N};
	if(a <= l && r <= b) return v[id];
	int m = (l+r)/2;
	pii esq = query(a,b,id*2,l,m);
	pii dir = query(a,b,id*2+1,m+1,r);
	return {min(esq.fi, dir.fi), max(esq.se, dir.se)};  
}

void upd(int a, int b, int val, int id=1, int l=1, int r=n) {
	prop(id,l,r);
	if(a > r || b < l) return;
	if(a <= l && r <= b) {
		lazy[id] += val;
		prop(id,l,r);
		return;
	}

	int m = (l+r)/2;
	upd(a,b,val,id*2,l,m);
	upd(a,b,val,id*2+1,m+1,r);
	v[id].fi = min(v[id*2].fi, v[id*2+1].fi);
	v[id].se = max(v[id*2].se, v[id*2+1].se);
}


int main () {

	return 0;
}



