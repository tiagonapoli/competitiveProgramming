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
#define N 1001000

vector<ll> p;
int c[N];

void sieve() {
	for(int i=2;i<N;i++) {
		if(c[i] == 0) p.pb(i);
		for(int j=i;j<N;j+=i) c[j] = 1;			
	}
}


int main () {

	sieve();

	ll n = nxtll();

	if(n == 1) {
		printf("1\n");
		return 0;
	}

	vector<ll> f;
	for(auto el : p) {
		if(n % el == 0) f.pb(el);
		while(n % el == 0) n /= el;
	}

	if(n > 1) f.pb(n);

	if(f.size() > 1) {
		printf("1\n");
	} else printf("%lld\n", f[0]);

	return 0;
}



