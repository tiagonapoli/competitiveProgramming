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
#define N 100100

int n;
priority_queue<pii> pq;
int v[N];
int res[N];
vector<int> cnt[N];

int xin, yin;

int getMax() {
  auto el = pq.top(); pq.pop();
  prinpar(el);
  el.fi--;
  
  if (el.fi > 0) pq.push(el);
  int ret = cnt[el.se].back();
  cnt[el.se].pop_back();
  return ret;
}

void check() {
  int common = 0;
  for(int i=0;i<n;i++) {
    if(v[i] == res[i]) common++;
  }

  prin(common);
  prin(xin);

  assert(common == xin);

  map<int, int> aux;
  for(int i=0;i<n;i++) {
    aux[res[i]]++;
  }

  common = 0;
  for(int i=0;i<n;i++) {
    if(aux[v[i]] > 0) {
      common++;
      aux[v[i]]--;
    }
  }

  prin(common);
  prin(yin);
  assert(common == yin);
}

int main() {

  int t = nxt();
  while (t--) {
    n = nxt();
    int x = nxt();
    xin = x;
    yin = nxt();
    int y = n - yin;
    prin(y);
    set<int> correct;

    For(i, 0, n + 2) cnt[i].clear();
    while (!pq.empty()) pq.pop();
    generate(v, v + n, nxt);

    For(i, 0, n) {
      cnt[v[i]].pb(i);
      res[i] = -1;
    }

    int missing = -1;
    For(i, 1, n + 2) {
      if (cnt[i].size() > 0) pq.push({ (int)cnt[i].size(), i });
      else if(missing == -1) missing = i;
    }

    prin(missing);

    For(i, 0, x) {
      int id = getMax();
      res[id] = v[id];
      correct.insert(id);
      prin(id);
    }
    sepd();

    if(debug) For(i,0,n) printf("%d ", res[i]);
    sepd();

    prin(pq.top().fi);
    int forcedPositions = 0;
    if(pq.size() > 0) forcedPositions = max(0, 2 * pq.top().fi - (n - x));
    prin(forcedPositions);
    if (y < forcedPositions) {
      printf("NO\n");
      continue;
    }

    vector<int> swapAux;
    int maxi = -1;
    For(i, 0, n + 2) {
      int sz = cnt[i].size();
      maxi = max(sz, maxi);
      swapAux.insert(swapAux.end(), all(cnt[i]));
    }

    if(debug) For(i,0,n) printf("%d ", res[i]);
    sepd();

    For(i, 0, (int)swapAux.size()) {
      int b = (i + maxi) % swapAux.size();
      prin(swapAux[i]);
      res[swapAux[b]] = v[swapAux[i]];
    }


    if(debug) For(i,0,n) printf("%d ", res[i]);
    sepd();

    int freeChanges = y - forcedPositions;
    For(i, 0, n) {
      if (res[i] == v[i] && !correct.count(i)) {
        // assert(y > 0);
        res[i] = missing;
        y--;
      } else if(!correct.count(i) && freeChanges > 0) {
        // assert(y > 0);
        res[i] = missing;
        freeChanges--;
        y--;
      }
    }

    printf("YES\n");
    For(i, 0, n) printf("%d ", res[i]);
    sep();
    // check();
  }


  return 0;

}
