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

ll v[N];
ll findBest(int a, int b, int l, int r) {
	sort(v+a, v+b);
	sort(v+l, v+r);
	ll s = 0;
	for (int i=l;i<r;i++) s += v[i];
	for(int i=a,j=r-1;i<b && j >= l;i++,j--) {
		if(v[i] < v[j]) {
			s += v[i] - v[j];
		}
	}

	return s;
}

int main () {

	int t = nxt();
	while(t--) {
		int n = nxt();
		int l = nxt();
		int r = nxt();
		l--;

		for (int i=0;i<n;i++) v[i] = nxt();

		ll res = min(findBest(0, l, l, r), findBest(r, n, l, r));
		printf("%lld\n", res);
	}

	return 0;

}



