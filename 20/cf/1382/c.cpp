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

string a,b;

int main () {

    int t = nxt();
    while(t--) {
        int n = nxt();
        cin >> a >> b;

        int inv = 0;
        int p1, p2;
        p1 = 0;
        p2 = n-1;
        vector<int> res;
        for(int i=n-1;i>=0;i--) {
            prin(i);
            prin(p1);
            prin(p2);
            prin(inv);
            prin(a[p1]);
            prin(b[i]);

            if((inv == 1 && a[p1] != b[i]) || (inv == 0 && a[p1] == b[i])) {
                res.pb(1);
                prin("inverte primeiro");
            }
            
            if(p1 < p2) {
                p1++;
            } else p1--;
            res.pb(i+1);
            swap(p1,p2);
            inv = !inv;
            sepd();
        }

        printf("%d ", (int) res.size());
        for(int x : res) printf("%d ", x);
        sep();
    }

    return 0;
}
