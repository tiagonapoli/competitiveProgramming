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
#define N 200100

const int INF = 100000000;

// minCost[i][j] is the minimum cost to reach state j given that initial state is i and input for the automata is fixed
// The automataNode is used in the segment tree, and the input string in the range represented by that node in the segment tree 
struct automataNode {
	int minCost[5][5];

	automataNode() {
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) minCost[i][j] = INF;
		}
	}

	void print() {
		for(int i=0;i<5;i++) {
			printf("%d: ", i);
			for(int j=0;j<5;j++) minCost[i][j] == INF ? printf("- ") : printf("%d ", minCost[i][j]);
			printf("\n");
		}
		printf("\n");
	}

	friend automataNode operator* (const automataNode &a, const automataNode &b) {
		automataNode r = automataNode();
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				for(int k=0;k<5;k++) {
					r.minCost[i][j] = min(r.minCost[i][j], a.minCost[i][k] + b.minCost[k][j]);
				}
			}
		}

		return r;
	}
};

// The automata is the following - (charInput, nextState, cost)
// initialState: (2, initialState, 1), (2, '2', 0), (any other char, initialState, 0)
// A cost of 1 means that we're deleting that char from the input - we're paying the cost to not go to another state
// '2': (0, '2', 1), (0, '20', 0), (any other char, '2', 0)
// '20': (1, '20', 1), (1, '201', 0), (any other char, '20', 0)
// '201': (6, '201', 1), (7, '2017', 0), (any other char, '201', 0)
// '2017': (6, '2017', 1), (any other char, '2017', 0)

int n;
automataNode seg[4*N];
string s;

automataNode query(int a, int b, int id=1, int l=1, int r=n) {
	if(a <= l && r <= b) {
		return seg[id];
	}

	int m = (l + r) / 2;
	if(b <= m) return query(a, b, id*2, l, m);
	if(a > m) return query(a,b,id*2+1, m+1, r);
	return query(a, b, id*2, l, m) * query(a, b, id*2+1, m+1, r);
}

void build(int id=1, int l=1, int r=n) {
	if(l == r) {
		seg[id] = automataNode();
		for(int i=0;i<5;i++) seg[id].minCost[i][i] = 0;
		switch (s[l-1]) {
			case '2':
				seg[id].minCost[0][1] = 0;
				seg[id].minCost[0][0] = 1;
				break;
			case '0':
				seg[id].minCost[1][2] = 0;
				seg[id].minCost[1][1] = 1;
				break;
			case '1':
				seg[id].minCost[2][3] = 0;
				seg[id].minCost[2][2] = 1;
				break;
			case '7':
				seg[id].minCost[3][4] = 0;
				break;
			case '6':
				seg[id].minCost[3][3] = 1;
				seg[id].minCost[4][4] = 1;
				break;
		}

		if(debug) {
			printf("ID: %d [%d, %d]\n", id, l ,r);
			seg[id].print();
		}

		return;
	}

	int m = (l + r) / 2;
	build(id*2, l, m);
	build(id*2+1, m+1, r);
	seg[id] = seg[id*2] * seg[id*2+1];

	if(debug) {
		printf("ID: %d [%d, %d]\n", id, l ,r);
		seg[id].print();
	}
}

int main () {

	int q;

	cin >> n >> q;

	cin >> s;

	build();

	while(q--) {
		int a,b;
		a = nxt(), b = nxt();
		automataNode r = query(a,b);
		printf("%d\n", r.minCost[0][4] != INF ? r.minCost[0][4] : -1);
	}

	return 0;

}



