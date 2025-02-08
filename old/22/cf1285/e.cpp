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

map<int, vector<int>[2]> events;
int bridgePts[N];
pii seg[N];

pii sweepline() {
	int res = 0;
	int possibleBridge = -1;
	int openedInUnion = 0;
	int maxOpened = 0;

	set<int> open;
	for(auto &coordinate : events) {

		prin(coordinate.fi);
		auto &openEv = coordinate.se[0];
		auto &closeEv = coordinate.se[1];

		if(possibleBridge != -1 && openEv.size() > 0) {
			if(debug) printf("found bridge %d %d->%d\n", possibleBridge, seg[possibleBridge].fi, seg[possibleBridge].se);
			bridgePts[possibleBridge]++;
			possibleBridge = -1;
		}

		// open all
		for(auto &ev : openEv) {
			if(debug) printf("open %d %d->%d\n", ev, seg[ev].fi, seg[ev].se);
			open.insert(ev);
			openedInUnion++;
		}

		maxOpened = max(maxOpened, openedInUnion);

		// close all
		for(auto &ev : closeEv) {
			if(debug) printf("close %d %d->%d\n", ev, seg[ev].fi, seg[ev].se);
			open.erase(ev);
		}

		prin(open.size());
		if(open.size() == 1 && openedInUnion > 1) {
			possibleBridge = *open.begin();
			prin(possibleBridge);
			prinpar(seg[possibleBridge]);
			sepd();
		}

		if(open.size() == 0) {
			res++;
			openedInUnion = 0;
			possibleBridge = -1;
		}

		sepd();
	}

	return {res, maxOpened};
}

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		events.clear();
		for(int i=0;i<n;i++) {
			bridgePts[i] = 0;
			seg[i].fi = nxt();
			seg[i].se = nxt();
			events[seg[i].fi][0].pb(i);
			events[seg[i].se][1].pb(i);
		}

		auto resPair = sweepline();
		int total = resPair.fi;
		int maxOpenedInUnions = resPair.se;
		prin(total);
		prin(maxOpenedInUnions);

		int maxi = 0;
		for(int i=0;i<n;i++) {
			maxi = max(maxi, bridgePts[i]);
			if(debug) printf("[%d] %d->%d: %d\n", i, seg[i].fi, seg[i].se, bridgePts[i]);
		}

		if(maxi == 0 && maxOpenedInUnions == 1) {
			total--;
		}

		printf("%d\n", total + maxi);
	}


	return 0;

}



