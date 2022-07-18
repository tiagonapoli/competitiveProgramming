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

int divsUntilOdd(int x) {
	int res =0 ;
	while(x % 2 == 0) {
		x/=2;
		res++;
	}
	return res;
}

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		for(int i=0;i<n;i++) v[i] = nxt();
		int odd = 0;
		int bestDivsUntilOdd = 50;
		
		for(int i=0;i<n;i++) {
			if(v[i] % 2 == 1) odd++;
		}

		if(odd != 0) {
			printf("%d\n", n-odd);
		} else {
			for(int i=0;i<n;i++) {
				bestDivsUntilOdd = min(bestDivsUntilOdd, divsUntilOdd(v[i]));
			}

			printf("%d\n", bestDivsUntilOdd + n - 1);
		}
	}

	return 0;

}



