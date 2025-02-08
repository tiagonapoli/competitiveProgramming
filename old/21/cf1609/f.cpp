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
#define N 1001000

int rsolutions[N];
int minCntPerBitsRmax[64], minCntPerBitsRmin[64];
int maxCntPerBitsRmax[64], maxCntPerBitsRmin[64];
pair<ll, int> minR[N], maxR[N];
pair<ll, int> v[N];

ll merge(pii l, pii r) {
	pair<ll, int> maxi, mini, maxr, minr;
	minR[r.fi-1] = maxR[r.fi-1] = v[r.fi];
	rsolutions[r.fi - 1] = 0;
	for(int i=0;i<64;i++) minCntPerBitsRmax[i] = minCntPerBitsRmin[i] = maxCntPerBitsRmin[i] = maxCntPerBitsRmax[i] = 0;
	for(int i=r.fi;i<=r.se;i++) {
		maxR[i] = max(maxR[i-1], v[i]);
		minR[i] = min(minR[i-1], v[i]);
		rsolutions[i] = rsolutions[i-1] + (maxR[i].se == minR[i].se);
		prin(rsolutions[i]);
	}

	ll res = 0;
	int rmax, rmin;
	maxi = mini = v[l.se];
	rmax = rmin = r.fi;
	for(int i=l.se;i>=l.fi;i--) {
		maxi = max(maxi, v[i]);
		mini = min(mini, v[i]);
		while(rmax <= r.se && v[rmax] <= maxi) {
			minCntPerBitsRmax[minR[rmax].se]++;
			maxCntPerBitsRmax[maxR[rmax].se]++;
			rmax++;
		}

		while(rmin <= r.se && v[rmin] >= mini) {
			minCntPerBitsRmin[minR[rmin].se]++;
			maxCntPerBitsRmin[maxR[rmin].se]++;
			rmin++;
		}

		// Both MIN, MAX are on [l.fi, l.se]: r < rmin, rmax
		res += (maxi.se == mini.se) * (min(rmin, rmax) - r.fi);
		prin( (maxi.se == mini.se) * (min(rmin, rmax) - r.fi));

		if(rmin <= rmax) {
			// MAX is on [l.fi, l.se] and MIN is on [r.fi, r.se]: rmin <= r < rmax 
			res += minCntPerBitsRmax[maxi.se] - minCntPerBitsRmin[maxi.se];
			prin(minCntPerBitsRmax[maxi.se] - minCntPerBitsRmin[maxi.se]);
		} else {
			// MIN is on [l.fi, l.se] and MAX is on [r.fi, r.se]: rmax <= r < rmin
			res += maxCntPerBitsRmin[mini.se] - maxCntPerBitsRmax[mini.se];
			prin(maxCntPerBitsRmin[mini.se] - maxCntPerBitsRmax[mini.se]);
		}

		// Both MIN, MAX are on [r.fi, r.se]: r >= rmin, rmax
		res += rsolutions[r.se] - rsolutions[max(rmin, rmax) - 1];
		prin(rsolutions[r.se] - rsolutions[max(rmin, rmax) - 1]);
	}

	return res;
}

ll solve(int l, int r) {
	if(l == r) return 1;
	int m = (l + r) / 2;
	return solve(l, m) + solve(m+1, r) + merge({l,m}, {m+1, r});
}

int main () {

	int n = nxt();
	for(int i=1;i<=n;i++) {
		scanf("%lld", &v[i].fi);
		v[i].se = __builtin_popcountll(v[i].fi);
	}

	printf("%lld\n", solve(1, n));

	return 0;

}



