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
		string s;
		cin >> s;

		ll r1 = 0;
		ll r2 = 0;
		ll aux1 = 1;
		ll aux2 = 1;

		for(int i=s.size() - 1; i >= 0; i--) {
			if(i % 2 == 0) {
				r1 += aux1 * (s[i] - '0');
				aux1 *= 10;
			} else {
				r2 += aux2 * (s[i] - '0');
				aux2 *= 10;
			}
		}

		prin(r1);
		prin(r2);
		printf("%lld\n", (r1 + 1) * (r2 + 1) - 2);

	}


	return 0;

}



