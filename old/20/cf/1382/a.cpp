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

int a[N], b[N];

int main () {

    int t = nxt();

    while(t--) {
        int n = nxt();
        int m = nxt();
        generate(a,a+n,nxt);
        generate(b,b+m,nxt);
        For(i,0,n) {
            For(j,0,m) {
                if(a[i] == b[j]) {
                    printf("YES\n");
                    printf("1 %d\n", a[i]);
                    goto fini;
                }
            }
        }

        printf("NO\n");
        fini:;
    }

    return 0;

}
