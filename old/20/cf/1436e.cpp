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
#define N 100100

int seg[4*N];
int inf = 1e9;
int v[N];
int n;

int qry(int a, int b, int id=1, int l=1, int r=n) {
	if(a > r || b < l) return inf;
	if(a <= l && r <= b) return seg[id];
	int mid = (l+r)/2;
	return min(qry(a,b, id*2,l,mid), qry(a,b,id*2+1,mid+1,r));
}

void upd(int pos, int val, int id=1, int l=1, int r=n) {
	if(l == r) {
		seg[id] = val;
		return;
	}

	int mid = (l+r)/2;
	if(pos <= mid) {
		upd(pos, val, id*2, l, mid);
	} else upd(pos, val, id*2+1, mid+1, r);
	seg[id] = min(seg[id*2], seg[id*2+1]);
}

vector<int> p[N];
int res[N];

int main () {

	n = nxt();
	For(i,1,n+1) upd(i,-inf);

	generate(v+1,v+n+1,nxt);
	For(i,1,n+2) {
		p[i].pb(0);
	}

	For(i,1,n+1) {
		p[v[i]].pb(i);
	}

	For(i,1,n+2) {
		p[i].pb(n+1);
	}

	vector<pair<pii, pii>> q;
	For(i,1,n+2) {
		if(debug) printf("%d: ", i);
		For(j,1,(int)p[i].size()) {
			if(p[i][j-1]+1 <= p[i][j]-1) {
				q.pb({{p[i][j]-1,p[i][j-1]+1}, {i,0}});
			}
			if(debug) printf("%d ", p[i][j]);
		}
		sepd();
	}

	sort(all(q));
	prin(q.size());
	for(auto el : q) {
		if(debug) printf("%d->%d %d/%d\n", el.fi.se, el.fi.fi, el.se.fi, el.se.se);
	}


	int ptr = 0;
	for(int r=1;r<=n;r++) {
		upd(v[r],r);
		prin(r);
		if(debug) for(int j=1;j<=n;j++) printf("%d ", qry(j,j));
		sepd();

		while(ptr < (int)q.size() && q[ptr].fi.fi == r) {
			auto &el = q[ptr];
			if(debug) printf("%d->%d %d\n", el.fi.se, el.fi.fi, el.se.fi);
			int lowerId = qry(1, el.se.fi-1);
			prin(lowerId);
			prin(el.fi.se);
			if(el.fi.se <= lowerId) {
				el.se.se = 1;
			} else {
				el.se.se = 0;
			}
			prin(el.se.se);
			ptr++;
		}
	}

	for(auto el : q) {
		prin(el.se.se);
		if(el.se.se == 1) {
			// There exists l,r such that MEX(l,r) = k = q[ptr].se.fi
			res[el.se.fi] = 1;
		}
	}

	sepd();

	for(int i=1;i<=n+2;i++) {
		if(res[i] == 0) {
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}
