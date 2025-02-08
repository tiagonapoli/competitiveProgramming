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
#define N 2100

int d[N][N];
int n,m;
int dirx[] = {+1,-1,0,0};
int diry[] = {0,0,-1,1};
char grid[N][N];

void bfs(int a, int b) {
	deque<pii> fila;
	For(i,1,n+1) For(j,1,m+1) d[i][j] = -1;
	fila.push_back({a,b});
	d[a][b] = 0;
	while(!fila.empty()) {
		auto now = fila.front(); fila.pop_front();
		for(int i=0;i<4;i++) {
			int x = dirx[i] + now.fi;
			int y = diry[i] + now.se;
			if(grid[x][y] == '*') continue;
			auto cost = d[now.fi][now.se] + (i==3);
			if(d[x][y] == -1 || d[x][y] > cost) {
				d[x][y] = cost;
				if(i == 3) {
					fila.push_back({x,y});
				} else {
					fila.push_front({x,y});
				}
			}
		}
	}
}


int main () {

	n = nxt();
	m = nxt();

	int r,c;
	r = nxt();
	c = nxt();

	int x,y;
	x = nxt();
	y = nxt();

	For(i,1,n+1) For(j,1,m+1) scanf(" %c", &grid[i][j]); 
	For(i,0,N) For(j,0,N) d[i][j] = 0;
	bfs(r,c);
	
	int res = 0;
	For(i,1,n+1) {
		For(j,1,m+1) {
			if(d[i][j] != -1 && d[i][j] <= y && d[i][j]+c-j <= x) res++;
			if(debug) printf("%2d ", d[i][j]);
		}
		sepd();
	}

	printf("%d\n", res);
	return 0;

}



