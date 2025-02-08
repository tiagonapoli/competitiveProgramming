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
#define N 10100

int dist[N][1010];
int d[N];
int n, g, r;

void relaxation0(pii now, int nxt, deque<pii> &q) {
	if(nxt >= n || nxt < 0) return;
	int nxtTime = now.se - abs(d[now.fi] - d[nxt]);
	if(nxtTime >= 0 && dist[nxt][nxtTime] == -1) {
		dist[nxt][nxtTime] = dist[now.fi][now.se];
		q.push_front({ nxt, nxtTime });
	}
}

void relaxation1(pii now, deque<pii> &q) {
	if(dist[now.fi][g] == -1) {
		dist[now.fi][g] = dist[now.fi][now.se] + 1;
		q.push_back({now.fi, g});
	}
}

void bfs01(pii ini) {
	deque<pii> q;

	for(int i=0;i<n;i++) {
		for(int j=0;j<=g;j++) dist[i][j] = -1;
	}

	q.push_front(ini);
	dist[ini.fi][ini.se] = 0;

	while(!q.empty()) {
		pii now = q.front();
		if(debug) printf("%d/%d %d\n", now.fi, now.se, dist[now.fi][now.se]);
		q.pop_front();

		if(now.se != 0) {
			relaxation0(now, now.fi - 1, q);
			relaxation0(now, now.fi + 1, q);
		} else relaxation1(now, q);
	} 

}

int main () {

	nxt();
	n = nxt();

	for(int i=0;i<n;i++) {
		d[i] = nxt();
	}

	sort(d, d+n);
	g = nxt();
	r = nxt();

	bfs01({ 0, g });

	int mini = 1000000000;

	sepd();
	for(int i=g;i>=0;i--) {
		if(debug) printf("[%d] %d\n", i, dist[n-1][i]);	
		if(dist[n-1][i] != -1) {
			mini = min(mini, r * dist[n-1][i] + g * dist[n-1][i] + g - i);
		} 
	}

	if(mini == 1000000000) {
		printf("-1\n");
	} else printf("%d\n", mini);

	return 0;

}



