#include "bits/stdc++.h"
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

#ifdef DEBUG
    const bool debug = 1;
#else
    const bool debug = 0;
#endif

#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define sepd() if(debug) cout << endl
#define sep() printf("\n");

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 100100

int v[N];
int r[N];

int main () {

    int t = nxt();

    while(t--) {
        int n = nxt();
        generate(v, v+n, nxt);
        int win = 0;
        r[n-1] = 1;
        for(int i=n-2;i>=0;i--) {
            if(v[i] == 1) {
                r[i] = !r[i+1];
            } else r[i] = 1;
        }

        For(i,0,n) {
            prin(i);
            prin(r[i]);
        }

        printf("%s\n", r[0] == 1 ? "First" : "Second");
    }

    return 0;
}
