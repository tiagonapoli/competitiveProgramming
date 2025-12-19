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

ll a[N];
ll b[N];
vector<ll> pairsA;
vector<ll> pairsB;

int main () {

	int t = nxt();
	while(t--) {
		int n = nxt();
		int m = nxt();
		pairsA.clear();
		pairsB.clear();
		for(int i=0;i<n;i++) a[i] = nxt();
		for(int i=0;i<m;i++) b[i] = nxt();
		sort(a, a+n);
		sort(b, b+m);

		pairsA.pb(0);
		pairsB.pb(0);
		for(int i=0;i<n-i-1;i++) pairsA.pb(a[n-i-1] - a[i]);
		for(int i=0;i<m-i-1;i++) pairsB.pb(b[m-i-1] - b[i]);

		if(debug) {
			for(int i=0;i<(int)pairsA.size();i++) printf("%lld ", pairsA[i]);
			sep();
			for(int i=0;i<(int)pairsB.size();i++) printf("%lld ", pairsB[i]);
			sep();
		}
		
		for(int i=1;i<(int)pairsA.size();i++) pairsA[i] += pairsA[i-1];
		for(int i=1;i<(int)pairsB.size();i++) pairsB[i] += pairsB[i-1];

		if(debug) {
			for(int i=0;i<(int)pairsA.size();i++) printf("%lld ", pairsA[i]);
			sep();
			for(int i=0;i<(int)pairsB.size();i++) printf("%lld ", pairsB[i]);
			sep();
		}

		int kMax = min(n, min(m, (m+n)/3));
		printf("%d\n", kMax);
		int theoricMaxA = n;
		int theoricMaxB = m;
		int cntA = 0;
		int cntB = 0;
		for(int i=1;i<=kMax;i++) {
			theoricMaxA = max(0, theoricMaxA - 1);
			theoricMaxB = max(0, theoricMaxB - 1);
			int maxA = min(theoricMaxA, (int)pairsA.size() - 1);
			int maxB = min(theoricMaxB, (int)pairsB.size() - 1);
			cntA = min(cntA, maxA);
			cntB = min(cntB, maxB);
			while(cntA < maxA && cntB < maxB && cntA + cntB < i) {
				if(pairsA[cntA+1] + pairsB[cntB] > pairsA[cntA] + pairsB[cntB+1]) {
					cntA++;
				} else {
					cntB++;
				}
			}
			
			while(cntA < maxA && cntA + cntB < i) {
				cntA++;
			}

			while(cntB < maxB && cntA + cntB < i) {
				cntB++;
			}

			if(debug) printf("[%d] %d/%d  %d/%d\n", i, cntA, maxA, cntB, maxB);
			printf("%lld ", pairsA[cntA] + pairsB[cntB]);
		}

		sep();
	}

	return 0;

}

