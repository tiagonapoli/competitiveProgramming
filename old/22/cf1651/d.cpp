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
inline ll nxtll() { ll x; scanf("%lld", &x); return x; }
#define N 200100

pii p[N];
map<pii, pair<int, pii>> d;
int n;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs() {

	queue<pair<int, pii>> q;

	for(int i=0;i<n;i++) {
		for(int j=0;j<4;j++) {
			pii nxt = { p[i].fi + dx[j], p[i].se + dy[j] };
			if(d.find(nxt) == d.end()) {
				q.push({1, p[i]});
				d[p[i]] = {1, nxt};
				break;
			}
		}
	}

	while(!q.empty()) {
		auto el = q.front(); q.pop();
		auto now = el.se;

		if(debug) printf("now: %d,%d [%d]\n", now.fi, now.se, el.fi);

		for(int i=0;i<4;i++) {
			pii nxt = { now.fi + dx[i], now.se + dy[i] };
			if(d.find(nxt) == d.end()) continue;
			if(d[nxt].fi != -1) continue;
			d[nxt] = { el.fi + 1, d[now].se };
			q.push({ el.fi + 1 , nxt });
		}
	}
	

}

int main() {

	n = nxt();
	for(int i=0;i<n;i++) {
		scanf("%d %d", &p[i].fi, &p[i].se);
		d[p[i]] = {-1, {0,0}};
	}

	bfs();

	for(int i=0;i<n;i++) {
		auto el = d[p[i]];
		if(debug) printf("%d,%d: %d,%d [%d]\n", p[i].fi, p[i].se, el.se.fi, el.se.se, el.fi);
		else printf("%d %d\n", el.se.fi, el.se.se);
	}

	return 0;
}



