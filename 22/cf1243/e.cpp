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
#define N 100000

map<int, vector<pair<int, pii>>> sets;
int k;
vector<pii> v[N];
vector<int> adj[N];

map<int, int> idToBox;
map<int, int> idToNumber;
map<int, int> numberToBox;
pair<bool, int> dp[N];
bool vis[N];

int dfs(int first, int now, vector<pair<int, pii>> &ops) {
	if(debug) printf("%d %d\n", first, now);
	vis[now] = 1;
	for(auto el : adj[now]) {
		if(el == first) {
			ops.pb({idToBox[now], {idToNumber[now], idToBox[el]}});
			return 1 << idToBox[el];
		}

		int aux = dfs(first, el, ops);		
		if(aux > 0) {
			ops.pb({idToBox[now], {idToNumber[now], idToBox[el]}});
			return aux + (1 << idToBox[el]);
		}
	}

	return 0;
}

int main () {
	
	k = nxt();

	map<ll, int> a;
	ll s = 0;
	int cnt = 0;
	ll sumPerBox[N];
	for(int i=0;i<k;i++) {
		int n = nxt();
		sumPerBox[i] = 0;
		for(int j=0;j<n;j++) {
			v[i].pb({nxt(), cnt});
			a[v[i].back().fi] = cnt;
			idToBox[cnt] = i;
			idToNumber[cnt] = v[i].back().fi;
			numberToBox[v[i].back().fi] = i;
			s += v[i].back().fi;
			sumPerBox[i] += v[i].back().fi;
			cnt++;
		}
	}

	s /= k;
	for(int i=0;i < k; i++) {
		for(int j=0;j<(int)v[i].size();j++) {
			ll aux = s - sumPerBox[i] + (ll)v[i][j].fi;
			if(a.find(aux) == a.end()) continue;
			auto el = a[aux];
			if(el != v[i][j].se && idToBox[el] == i) continue;
			adj[el].pb(v[i][j].se);
		}
	}

	// build sets of cycles
	for(int i=0;i<cnt;i++) {
		if(vis[i] == 0) {
			vector<pair<int, pii>> ops;
			int aux = dfs(i, i, ops);
			prin(aux);
			sepd();
			if(aux > 0) {
				sets[aux] = ops;
				if(debug) {
					printf("0x%x\n", aux);
					for(auto el : sets[aux]) printf("%d %d->%d ", el.fi, el.se.fi, el.se.se);
					sepd();
				}
			}
		}
	}

	dp[0] = {1, 0};
	for(int mask=1;mask<(1<<k);mask++) {
		for(int submask=mask;submask>0;submask=(submask-1) & mask) {
			if(sets.find(submask) == sets.end()) continue;
			if(dp[mask - submask].fi == 1) {
				prin(mask);
				prin(submask);
				prin(mask - submask);
				dp[mask] = {1, submask};
				break;
			}
		}
		prin(mask);
		prin(dp[mask].fi);
		prin(dp[mask].se);
		sepd();
	}

	if(dp[(1<<k) - 1].fi != 1) {
		printf("No\n");
		return 0;
	}

	printf("Yes\n");
	int now = (1 << k) - 1;
	vector<pair<int, pii>> res;
	while(now > 0) {
		for(auto el : sets[dp[now].se]) res.pb(el);
		now = now - dp[now].se;
	}

	sort(res.begin(), res.end());
	for(auto el : res) printf("%d %d\n", el.se.fi, el.se.se + 1);

	return 0;

}



