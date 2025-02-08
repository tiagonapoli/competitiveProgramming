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
#define N 1001000

int grid[3][N];
int obj[2][N];
int v[2][N];
int n, m;

int solve() {
	int res = N;
	For(i,0,2) For(j,0,2) {
		int diff = 0;
		For(pos,0,n) {
			if(m == 3 && (v[0][pos] != obj[i][pos] || v[1][pos] != obj[j][pos])) {
				diff++;
			} else if(m == 2 && v[0][pos] != obj[i][pos]) {
				diff++;
			}
		}
		res = min(diff, res);
	}

	return res;
}

int main () {

	obj[0][0] = 1;
	obj[1][0] = 0;
	For(j,0,2) For(i,1,N) {
		obj[j][i] = !obj[j][i-1];
	}

	int x,y;
	x = nxt();
	y = nxt();
	if(x >= 4 || x == 1) {
		int aux = x*y;
		while(aux--) scanf(" %*c");
		if(x >= 4) printf("-1\n");
		else printf("0\n");
		return 0;
	}

	For(i,0,x) For(j,0,y) {
		char c;
		scanf(" %c", &c);
		grid[i][j] = c - '0';
	}	

	For(i,0,y) {
		v[0][i] = grid[0][i] + grid[1][i];
		v[1][i] = grid[1][i] + grid[2][i];
		v[0][i] %= 2;
		v[1][i] %= 2;
	}
	
	n = y;
	m = x;
	printf("%d\n", solve());

	return 0;

}



