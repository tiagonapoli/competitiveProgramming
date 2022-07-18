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
#define N 500100

int v[N];

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		int s = nxt();
		for(int i=0;i<n;i++) v[i] = nxt();
 
		int pos = 0;
		int maxi = 0;
		while(pos < n) {
			s -= v[pos];
			if(v[pos] > v[maxi]) maxi = pos;
			if(s <= 0) break;
			pos++;
		}
 
		prin(pos);
		prin(maxi);
 
		if(pos == n || (s == 0 && v[pos+1] >= v[maxi])) {
			printf("0\n");
		} else printf("%d\n", maxi+1);
	}

	return 0;

}



