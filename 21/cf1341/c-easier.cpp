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
int inv[N];
bool done[N];

int check(int a, int b) {
    for(int i=a;i<b-1;i++) {
        if(v[i+1] != v[i] + 1) {
            return false;
        }
    }

    return true;
}

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();

		for(int i=0;i<n;i++) {
			int x = nxt();
            v[i] = x;
			inv[x] = i;
		}

        int barrier = n;
        for(int i=1;i<=n;) {
            if(!check(inv[i], barrier)) {
                printf("No\n");
                goto fim;
            }

            int newBarrier = inv[i];
            prin(i);
            prin(barrier);
            prin(newBarrier);
            sepd();
            i += barrier - inv[i];
            barrier = newBarrier;
        }
		
		printf("Yes\n");

		fim:;
	}

	return 0;

}



