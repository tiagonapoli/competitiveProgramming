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

int n,m;
char dict[] = { '#', '.', '+', 'L' };

int dx[] = { 1, -1, 0,  0};
int dy[] = { 0,  0, 1, -1};

bool checkPos(int x, int y, vector<vector<int>> &grid) {
	
	if(grid[x][y] != 1) return false;

	int free = 0;
	for(int i=0;i<4;i++) {
		if(grid[x + dx[i]][y + dy[i]] == 1) free++;
	}

	if(debug) printf("%d/%d free %d\n", x, y, free);
	return free <= 1;
}

void bfs(int x, int y, vector<vector<int>> &grid) {
	queue<pii> q;
	q.push({x,y});
	while(!q.empty()) {
		pii now = q.front(); q.pop();
		for(int i=0;i<4;i++) {
			int x1 = now.fi + dx[i];
			int y1 = now.se + dy[i];
			if(checkPos(x1, y1, grid)) {
				q.push({x1, y1});
				grid[x1][y1] = 2;
			}
		}
	}
}

int main () {

	int t = nxt();

	while(t--) {
		vector<vector<int>> grid;
		
		n = nxt();
		m = nxt();
		grid.resize(n+2);
		for(int i=0;i<n+2;i++) grid[i].resize(m+2);
		for(int i=0;i<n+2;i++) for(int j=0;j<m+2;j++) grid[i][j] = 0;

		int x, y;
		char c;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				scanf(" %c", &c);
				if(c == '.') grid[i][j] = 1;
				else if(c == 'L') {
					x = i;
					y = j;
					grid[i][j] = 2;
				}
			}
		}

		bfs(x, y, grid);
		grid[x][y] = 3;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				printf("%c", dict[grid[i][j]]);
			}
			printf("\n");
		}
	}

	return 0;

}



