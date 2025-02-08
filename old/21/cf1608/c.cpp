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
#define N 100100

int res[N];
int maxpref[N];
pair<pii, int> v[N];

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();

		for(int i=0;i<n;i++) res[i] = 0;

		for(int i=0;i<n;i++) v[i].fi.fi = nxt(), v[i].se = i;
		for(int i=0;i<n;i++) v[i].fi.se = nxt();

		sort(v, v+n);

		maxpref[0] = v[0].fi.se;
		for(int i=1;i<n;i++) {
			maxpref[i] = max(maxpref[i-1], v[i].fi.se);
		}

		res[v[n-1].se] = 1;
		int minToTheRightThatCanWin = v[n-1].fi.se;
		for(int i=n-2;i>=0;i--) {
			prin(maxpref[i]);
			prin(minToTheRightThatCanWin);
			sepd();
			if(maxpref[i] >= minToTheRightThatCanWin) {
				res[v[i].se] = 1;
				minToTheRightThatCanWin = min(v[i].fi.se, minToTheRightThatCanWin);
			}
		}
		
		for(int i=0;i<n;i++) printf("%d", res[i]);
		printf("\n");
	}

	return 0;

}



