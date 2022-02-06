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


int n;
int v[N], h[N];

inline int findFather(int x) {
	int k = 0;
	while((1 << k) < x) k++;
	return (1 << k) - x;
}

int goUp(int now, int u) {
    while(u > 0) {
        now = findFather(now);
        u--;
    }

    return now;
}

int lca(int i1, int i2) {
    if(h[i1] < h[i2]) swap(i1, i2);
    int v1 = goUp(v[i1], h[i1] - h[i2]), v2 = v[i2];
    int ret = h[i2];
    while(v1 != v2) {
        v1 = findFather(v1);
        v2 = findFather(v2);
        ret--;
    }

    return ret;
}

int dist(int i1, int i2) {
    return h[i1] + h[i2] - 2*lca(i1, i2);    
}

pii getMaxDist(int origin) {
    int d;
    pii maxd = {-1,-1};
    for(int i=0;i<n;i++) {
        d = dist(origin, i);
        if(debug) printf("dist %d->%d = %d\n", v[origin], v[i], d);
        if(maxd.fi < d) maxd = {d, i};
    }

    return maxd;
}

int main () {

    n = nxt();
    for(int i=0;i<n;i++) {
        v[i] = nxt();
        int x = v[i];
        while(x != 0) {
            x = findFather(x);
            h[i]++;
        }
    }

    pii maxd1 = getMaxDist(0);
    pii maxd2 = getMaxDist(maxd1.se);
    printf("%d %d %d\n", maxd1.se+1, maxd2.se+1, maxd2.fi);
}



