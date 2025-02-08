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
#define N 8800

int v[N];
int n;
vector<int> el;
bool dp[N][N];

void solve() {
  For(i, 0, n+2) For(j, 0, n+2) dp[i][j] = 0;
  dp[0][0] = 1;
  dp[0][el[0]] = 1;
  For(i, 1, (int) el.size()) {
    for (int j = n - 1;j >= 0;j--) {
      dp[i][j] = dp[i - 1][j];
      if (dp[i][j] == 1 && j + el[i] <= n) {
        dp[i][j + el[i]] = 1;
      }
    }
  }
}

int main() {

  int t = nxt();

  while (t--) {
    n = 2 * nxt();
    generate(v, v + n, nxt);
    el.clear();

    prin(n);
    int hi = n;
    while (hi > 0) {
      auto pos = max_element(v, v + hi) - v;
      prin(hi);
      prin(pos);
      prin(hi - pos);
      el.pb(hi - pos);
      hi = pos;
      sepd();
    }

    prin(el.size());
    for (int x : el) prin(x);
    solve();
    if(dp[el.size()-1][n/2]) {
      printf("YES\n");
    } else printf("NO\n");
  }


  return 0;

}
