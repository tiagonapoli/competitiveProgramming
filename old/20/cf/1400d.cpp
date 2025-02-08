#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

bool debug = 0;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define separa() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 100100

ll solve(int ind1, int ind2, vector<int> &b) {
	prin(ind1);
	prin(ind2);
	ll res = 0;
	ll p1 = lower_bound(b.begin(), b.end(), ind1) - b.begin();
	ll p2 = lower_bound(b.begin(), b.end(), ind2) - b.begin();
	ll sz = b.size();
	prin(p1);
	prin(p2);
	prin(sz);
	return (p2-p1) * (sz - p2) + p1 * (p2-p1);
}

int main () {

	int t, n;

	cin >> t;

	while(t--) {
		cin >> n;
		map<int, vector<int>> v;

		int x;
		for(int i=0;i<n;i++) {
			scanf("%d", &x);
			v[x].pb(i);
		}

		ll res = 0;
		for(auto it = v.begin(); it != v.end(); it++) {
			ll sz = (ll) it->se.size();
			res += sz*(sz-1LL)*(sz-2LL)*(sz-3LL)/24LL;
			prin(it->fi);
			prin(sz);
			prin(res);
			separa();

			for(auto it2 = next(it); it2 != v.end(); it2++) {
				prin(it->fi);
				prin(it2->fi);
				vector<int> *a = &it->se;
				vector<int> *b = &it2->se;

				if(a->size() > b->size()) {
					swap(a,b);
				}

				for(int i=0;i<a->size();i++) {
					for(int j=i+1;j<a->size(); j++) {
						res += solve((*a)[i], (*a)[j], *b);
						prin(res);
					}
				}
				separa();
			}
		}

		printf("%lld\n", res);
	}


	return 0;

}



