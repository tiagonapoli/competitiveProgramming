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

int digitCount(int x) {
	int r = 0;
	while(x > 0) {
		r++;
		x /= 10;
	}

	return r;
}

int main () {

	int t = nxt();

	while(t--) {
		int x1, p1, x2, p2;
		scanf("%d %d %d %d", &x1, &p1, &x2, &p2);

		int d1 = digitCount(x1) + p1;
		int d2 = digitCount(x2) + p2;

		if(d1 > d2) {
			printf(">\n");
			continue;
		}
		
		if(d1 < d2) {
			printf("<\n");
			continue;
		}

		while(digitCount(x2) != digitCount(x1)) {
			if(digitCount(x2) < digitCount(x1)) {
				x2 *= 10;
			} else x1 *= 10;
		}

		prin(x1);
		prin(x2);
		printf("%c\n", x2 < x1 ? '>' : x2 > x1 ? '<' : '=');
	}

	return 0;

}



