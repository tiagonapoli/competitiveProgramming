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
#define N 500100

vector<int> adj[N];
int h[N];
vector<int> arrh[N];
vector<int> path;
bool vis[N];
int maxh;
int n;

int dfs(int u) {
  maxh = max(h[u], maxh);
  prin(maxh);
  if (maxh >= (n + 1) / 2) {
    prin(u);
    path.pb(u);
    return 1;
  }

  arrh[h[u]].pb(u);
  vis[u] = 1;
  for (int v : adj[u]) {
    if (vis[v]) continue;
    h[v] = h[u] + 1;
    if (dfs(v)) {
      prin(u);
      path.pb(u);
      return 1;
    }
  }

  return 0;
}

int main() {

  int t = nxt();

  while (t--) {
    n = nxt();
    maxh = 0;
    path.clear();
    For(i, 0, n + 2) adj[i].clear();
    For(i, 0, n + 2) arrh[i].clear();

    int m = nxt();

    int a, b;
    For(i, 0, m) {
      a = nxt(); b = nxt();
      adj[a].pb(b);
      adj[b].pb(a);
    }

    h[1] = 1;
    For(i, 0, n + 2) vis[i] = 0;
    dfs(1);

    if (path.size() > 0) {
      printf("PATH\n%d\n", (int) path.size());
      for (int x : path) printf("%d ", x);
      sep();
      continue;
    }

    printf("PAIRING\n");

    int r = 0;
    for (int i = 0;i <= maxh;i++) r += arrh[i].size() / 2;
    printf("%d\n", r);
    For(i, 0, maxh+1) {
      prin(i);
      prin(arrh[i].size());
      for (int j = 1;j < (int)arrh[i].size();j += 2) {
        printf("%d %d\n", arrh[i][j], arrh[i][j - 1]);
      }
      sepd();
    }

  }

  return 0;

}