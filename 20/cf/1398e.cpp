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
#define N 200100

set<pii> s;
set<pii> ns;
ll s_sum, ns_sum;
int lcnt;
int s_fcnt;

void addS(pii x) {
	if(x.se == 0) s_fcnt++;
	s_sum += x.fi;
	s.insert(x);
}

void eraseS(pii x) {
	if(x.se == 0) s_fcnt--;
	s_sum -= x.fi;
	s.erase(x);
}

void addNs(pii x) {
	ns_sum += x.fi;
	ns.insert(x);
}

void eraseNs(pii x) {
	ns_sum -= x.fi;
	ns.erase(x);
}

int main () {

	int n;

	cin >> n;
	int a,b;
	for(int i=0;i<n;i++) {
		scanf("%d %d", &a, &b);
		if(b < 0) {
			if(ns.find({-b,a}) != ns.end()) eraseNs({-b,a});
			else eraseS({-b,a});
			if(a == 1) lcnt--;
		} else {
			addNs({b,a});
			if(a == 1) lcnt++;
		}
		
		while(ns.size() > 0 && s.size() > 0 && ns.rbegin()->fi > s.begin()->fi) {
			auto x = *s.begin();
			auto y = *ns.rbegin();
			eraseS(x);
			eraseNs(y);
			addS(y);
			addNs(x);
		}

		while(ns.size() > 0 && s.size() < lcnt) {
			auto x = *ns.rbegin();
			addS(x);
			eraseNs(x);
		}

		while(s.size() > lcnt) {
			auto x = *s.begin();
			addNs(x);
			eraseS(x);
		}

		prin(lcnt);
		prin(s_sum);
		prin(s_fcnt);
		prin(ns_sum);
		prin(s.size());
		prin(ns.size());

		if(s_fcnt > 0) {
			printf("%lld\n", 2*s_sum + ns_sum);
		} else {
			if(s.size() > 0) {
				ll add = 0;
				add -= s.begin()->fi;
				if(ns.size() > 0) add += ns.rbegin()->fi;
				printf("%lld\n", 2*s_sum + add + ns_sum);
			} else printf("%lld\n", ns_sum);
		}
	}
	


	return 0;

}



