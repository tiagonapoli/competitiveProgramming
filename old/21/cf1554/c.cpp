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
		int n = nxt();
		int m = nxt();

		if(n == 0) {
			printf("%d\n", m+1);
			continue;
		}


		int pos = 32 - __builtin_clz(n);
		int base = 1 << pos;

		int baseMex = (m / base) * base; 
		m %= base;
		prin(base);
		prin(baseMex);
		prin(m);

		int res = n;
		while(m > 0) {
			int nxt = n & (-n);
			n -= n & (-n);
			m -= nxt;
			if(m >= 0) res = n;
			prin(res);
			prin(nxt);
			prin(n);
			prin(m);
			sepd();
		}

		printf("%d\n", baseMex + res);
	}

	return 0;

}



