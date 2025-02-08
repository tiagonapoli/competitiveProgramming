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
#define N 200100

int v[N];
bool peak[N];

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		int k = nxt();

		for(int i=0;i<n;i++) {
			v[i] = nxt();
		}

		for(int i=0;i<n;i++) peak[i] = 0;

		for(int i=1;i<n-1;i++) {
			if(v[i-1] < v[i] && v[i] > v[i+1]) {
				peak[i] = 1;
			}
		}

		int r = 0;
		for(int i=1;i<k-1;i++) {
			r += peak[i];
		}

		int l = 0;
		int res = r;
		for(int i=k;i<n;i++) {
			r -= peak[i-k+1];
			r += peak[i-1];
			if(r > res) {
				res = r;
				l = i-k+1;
			}
		}

		printf("%d %d\n", res + 1, l + 1);
	}

	return 0;

}



