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
		int w, h;
		scanf("%d %d", &w, &h);

		vector<ll> hor[2];
		vector<ll> ver[2];
		int k = nxt();
		for(int i=0;i<k;i++) hor[0].pb(nxt());
		k = nxt();
		for(int i=0;i<k;i++) hor[1].pb(nxt());
		k = nxt();
		for(int i=0;i<k;i++) ver[0].pb(nxt());
		k = nxt();
		for(int i=0;i<k;i++) ver[1].pb(nxt());

		ll m = 0;
		m = max(m, (hor[0].back() - hor[0][0]) * h);
		m = max(m, (hor[1].back() - hor[1][0]) * h);
		m = max(m, (ver[0].back() - ver[0][0]) * w);
		m = max(m, (ver[1].back() - ver[1][0]) * w);
		printf("%lld\n", m);

	}

	return 0;

}



