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
#define N 100100

// Returns highest power of 2 <= x (or 0 if x == 0)
inline uint32_t highestBit(uint32_t x) {
    if (x == 0) return 0;
    return 1u << (31 - __builtin_clz(x));
}

int main () {

	int t = nxt();

	while(t--) {
		uint32_t n;
		int k;
		n = nxt();
		k = nxt();

		if (k == 1) {
			printf("%u ", n);
			sep();
			continue;
		}

		for (int i=0;i<k-2;i++) {
			printf("%u ", n);
		}

		if (k % 2 == 1) {
			printf("%u %u", n, n);
		} else {
			// extract second leftmost bit
			uint32_t hBit = highestBit(n);
			uint32_t secondHBit = highestBit(n - hBit);
	
			if (secondHBit == 0){
				printf("%u 0", n);
			} else {
				uint32_t a = hBit + secondHBit - 1;
				uint32_t b = n ^ a;
				printf("%u %u", a, b);
			}
		}
		
		sep()
	}


	return 0;

}

