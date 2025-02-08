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
inline int nxtll() { ll x; scanf("%lld", &x); return x; }
#define N 200100

vector<int> pos[N];
bool vis[N];
int v[N];
int n;

int main () {

	int t = nxt();

	while(t--) {
		scanf("%d", &n);
		vector<int> b;
		for(int i=0;i<=n+10;i++) {
			pos[i].clear();
			vis[i] = 0;
		}

		for(int i=0;i<n;i++) {
			scanf("%d", &v[i]);
		}

		for(int i=n-1;i>=0;i--) {
			pos[v[i]].pb(i);
		}

		int cur = 0;
		while(cur < n) {

			if(pos[0].size() == 0) {
				b.pb(0);
				cur++;
				continue;
			}

			int ini = cur;
			int mex = 0;
			for(;mex<=n;mex++) {
				if(vis[mex]) continue;

				auto &el = pos[mex];
				if(el.size() == 0) break;

				int aux = el.back();
				assert(aux >= cur);
				for(int j=cur;j<=aux;j++){ 
					assert(pos[v[j]].back() == j);
					pos[v[j]].pop_back();
					vis[v[j]] = 1;
					prin(j);
				}

				cur = max(cur, aux + 1);
			}

			for(int i=ini;i<cur;i++) {
				vis[v[i]] = 0;
				prin(i);
			}

			b.pb(mex);
		}

		printf("%d\n", b.size());
		for(int x : b) printf("%d ", x);
		printf("\n");
	}

	return 0;

}