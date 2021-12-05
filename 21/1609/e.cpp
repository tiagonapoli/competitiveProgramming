#include "bits/stdc++.h"
using namespace std;
#ifdef DEBUG
	const bool debug = 1;
#else
	const bool debug = 0;
#endif

#define prin(...) if(debug) logger(#__VA_ARGS__, __VA_ARGS__)
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define sepd() if(debug) cout << endl
#define sep() printf("\n");

template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
	cout << "\n";
}

#define For(i,a,b) for(int i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 100100

int INF = 100000000;

struct node {
	int m[4][4];

	void print(int l, int r) {
		if(!debug) return; 
		printf("%d -> %d\n", l, r);
		for(int i=0;i<4;i++) {
			printf("%d: ", i);
			for(int j=0;j<4;j++) printf("%d ", this->m[i][j]);
			printf("\n");
		}

		printf("\n\n");
	}
};

int n;
string s;
node seg[4*N];
int adj[4][4];

void merge(node &a, node &b, node &res) {
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			res.m[i][j] = INF;
			for(int k=0;k<4;k++) {
				res.m[i][j] = min(res.m[i][j], a.m[i][k] + b.m[k][j]); 
			}
		}
	}
}

void init(node &x, int letter) {
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) x.m[i][j] = INF;

		x.m[i][i] = 0;
		if(adj[i][letter] != i) {
			x.m[i][i] = 1;
			x.m[i][i+1] = 0;
		}
	}
}

void build(int id=1, int l=1, int r=n) {
	if(l == r) {
		init(seg[id], s[l-1] - 'a');
		seg[id].print(l ,r);
		return;
	}

	int m = (l + r)/2;
	build(id*2, l, m);
	build(id*2+1, m+1,r);
	merge(seg[id*2], seg[id*2+1], seg[id]);

	seg[id].print(l ,r);
}

void upd(int pos, int letter, int id=1, int l=1, int r=n) {
	if(l == r) {
		init(seg[id], letter);
		seg[id].print(l, r);
		return;
	}

	int m = (l + r)/2;
	if(pos <= m) {
		upd(pos, letter, id*2, l, m);
	} else upd(pos, letter, id*2+1, m+1, r);

	merge(seg[id*2], seg[id*2+1], seg[id]);
	seg[id].print(l ,r);
}

int main () {

	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) adj[i][j] = i;
	}

	adj[0][0] = 1;
	adj[1][1] = 2;
	adj[2][2] = 3;

	n = nxt();
	int q = nxt();

	cin >> s;

	build();

	while(q--) {
		int pos;
		char c;

		scanf("%d %c", &pos, &c);
		upd(pos, c - 'a'); 
		
		if(seg[1].m[0][3] == INF) {
			printf("0\n");
		} else {
			auto &r = seg[1];
			printf("%d\n", min(r.m[0][0], min(r.m[0][1], r.m[0][2])));
		}
	}

	return 0;

}



