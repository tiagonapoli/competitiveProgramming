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

int lvert[N];
int lhor[N];
int px[N];
int py[N];

pii v[N];

int n, m, k;

int horPos(int x) {
	return lower_bound(lhor, lhor+n+2, x) - lhor;
}

int verPos(int x) {
	return lower_bound(lver, lver+m+2, x) - lver;
}

int main () {

	int t = nxt();

	while(t--) {
		n = nxt();
		m = nxt();
		k = nxt();

		lver[0] = 0;
		lver[n+1] = 1000000;
		for(int i=1;i<=n;i++) {
			lver[i] = nxt();
		}

		sort(lver, lver+n);

		lhor[0] = 0;
		lhor[m+1] = 1000000;
		for(int i=1;i<=m;i++) {
			lhor[i] = nxt();
		}

		sort(lhor, lhor+m);

		for(int i=0;i<k;i++) {
			v[i].fi = nxt();
			v[i].se = nxt();
		}

		sort(v, v+k);

		ll res = 0;
		for(int i=0; i<k;i++) {
			// primeiro maior ou igual
			int h = verPos(v[i].fi);
			if(lvert[h] > v[i].fi) h--;
			res += i - lower_bound(v, v+k, lvert[h]) - v;
		}



		

	}

	return 0;

}



