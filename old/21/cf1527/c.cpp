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

int v[N];

map<int, vector<ll>> d;

int main () {

    int t = nxt();
    while(t--) {
        d.clear();

        ll n = nxt();
        for(int i=1;i<=n;i++) {
            v[i] = nxt();
            d[v[i]].pb(i);
        }

        ll res = 0;
        for(auto el : d) {
            ll s = 0;
            for(auto x : el.se) {
                s += n + 1 - x;
            }

            ll sz = el.se.size();
            prin(el.fi);
            for(ll i=0;i<sz;i++) {
                s -= n + 1 - el.se[i];
                res += el.se[i] * s;
                prin(el.se[i]);
                prin(res);
            }
            sepd();
        }

        printf("%lld\n", res);

    }
    
	return 0;

}


