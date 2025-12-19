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

int v[N];
int b[N];

ll acum[N];
ll minAcum[N];
ll maxAcum[N];

int main () {

	int t = nxt();
	while(t--) {
		int n = nxt();
		int k = nxt();

		for(int i=1;i<=n;i++) {
			v[i] = nxt();
		}
		
		minAcum[0] = 0;
		for (int i=1;i<=n;i++){
			acum[i] = acum[i-1] + v[i];
			minAcum[i] = min(acum[i], minAcum[i-1]);
		}

		maxAcum[n] = acum[n];
		for (int i=n-1;i>=1;i--) {
			maxAcum[i] = max(maxAcum[i+1], acum[i]);
		}

		for(int i=1;i<=n;i++){
			b[i] = nxt();
		}

		if (debug) {
			for(int i=0;i<=n;i++){
				printf("[%d]%lld ", i, acum[i]);
			}
			sep();
			for(int i=0;i<=n;i++){
				printf("[%d]%lld ", i, minAcum[i]);
			}
			sep();
			for(int i=0;i<=n;i++){
				printf("[%d]%lld ", i, maxAcum[i]);
			}
			sep();
		}

		ll best = v[1];
		for (int i=1; i<=n; i++) {
			ll sum = k % 2 == 0 ? 0 : b[i];
			prin(i);
			prin(sum);
			prin(minAcum[i-1]);
			prin(maxAcum[i]);
			sum -= minAcum[i-1];
			sum += maxAcum[i];
			prin(sum);
			best = max(best, sum);
			sepd();
		}

		printf("%lld\n", best);
	}

	return 0;

}

