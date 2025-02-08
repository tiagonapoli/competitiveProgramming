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

int x = 1000000000;
int v[N];

int main () {

	int t = nxt();
	while(t--) {
		int n = nxt();
		For(i,0,n) v[i] = nxt();
		sort(v,v+n);

		int dist = 1000000010;
		
		int cnt = 0;
		for(int i=0;i<n && v[i] <= 0; i++) {
			cnt++;
			if(i + 1 < n && v[i+1] <= 0) dist = min(dist, v[i+1] - v[i]);
		}

		prin(cnt);
		prin(dist);

		if(cnt < n && v[cnt] <= dist) {
			cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;

}



