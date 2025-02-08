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


int main () {

	int t = nxt();

	while(t--) {
		ll n = nxt();
		ll a = nxt();
		ll b = nxt();

		if(b == 1) {
			printf("Yes\n");
			continue;
		}

		if(a == 1) {
			printf("%s\n", n % b == 1 ? "Yes" : "No");
			continue;
		}

		ll x = 1;
		while(x <= n) {
			prin(x);
			prin(x%b);
			prin(n%b);
			sepd();
			if(x % b == n % b) {
				printf("Yes\n");
				goto fini;
			}

			x *= a;
		}

		printf("No\n");
		fini:;
	}

	return 0;

}



