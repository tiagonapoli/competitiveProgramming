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

bool inter(int x1, int y1, int x2, int y2) {
	if(x1 > x2) {
		swap(x1, x2);
		swap(y1, y2);
	}

	if(debug) printf("\n%d %d %d %d\n", x1, y1, x2, y2);

	if(y1 >= x2) return true;
	return false;
}

int main () {

	int t = nxt();

	while(t--) {
		int a, b, c ,d;
		
		int n = nxt();
		a = nxt();
		b = nxt();
		c = nxt();
		d = nxt();

		if(inter(n * (a - b), n * (a + b), c - d, c + d)) {
			printf("Yes\n");
		} else printf("No\n");
	}

	return 0;

}



