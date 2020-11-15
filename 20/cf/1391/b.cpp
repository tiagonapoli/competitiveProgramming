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
#define N 200

char v[N][N];
int r[N][N];
int changes = 0;
int dx[] = {0,-1};
int dy[] = {-1,0};
int n,m;

void printgrid() {
	if(!debug) return;
	For(i,0,n+2) {
		For(j,0,m+2) {
			printf("%d ", r[i][j]);
		}
		sep();
	}
	sep();
}

void solve(int a, int b) {
	queue<pii> fila;
	fila.push({a,b});
	while(!fila.empty()) {
		auto now = fila.front(); fila.pop();
		if(r[now.fi][now.se] == 1) continue;
		pii prox = now;
		prinpar(now);
		if(v[now.fi][now.se] == 'R') {
			prox.se++;
		} else if(v[now.fi][now.se] == 'D') prox.fi++;
		
		prinpar(prox);
		r[now.fi][now.se] = 1;
		if(r[prox.fi][prox.se] < 0) {
			changes++;
		}

		for(int i=0;i<2;i++) {
			prox = make_pair(now.fi + dx[i], now.se + dy[i]);
			if(r[prox.fi][prox.se] != -1) continue;
			fila.push(prox);
		}
		printgrid();
	}
}

int main () {
	
	int t = nxt();

	while(t--) {
		changes = 0;
		n = nxt();
		m = nxt();

		For(i,0,n+2) For(j,0,m+2) r[i][j] = -2;
		For(i,1,n+1) For(j,1,m+1) r[i][j] = -1;
		
		For(i,1,n+1) For(j,1,m+1) {
			scanf(" %c", &v[i][j]);
		}

		solve(n,m);
		printf("%d\n", changes);
	}



	return 0;

}



