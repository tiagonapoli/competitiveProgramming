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

ll v[N];

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		ll k = nxt();

		for(int i=0;i<n;i++) {
			v[i] = nxt();
		}

		if(v[0] != 0) {
			printf("1\n");
			continue;
		}

		k++;

		for(int i=0;i<n;i++) {
			v[i] = pow(10, v[i]);
		}

		int i =0;

		ll acum = 0;
		for(;i<n-1 && k > 0;i++) {
			ll allowed = v[i+1] / v[i] - 1;
			acum += v[i] * min(k, allowed);
			k -= min(k, allowed);
		}

		acum += k * v[i];
		printf("%lld\n", acum);
	}

	return 0;

}



