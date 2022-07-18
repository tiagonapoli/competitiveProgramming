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
#define N 100100


int main () {

	int k = nxt();

	while(k--) {
		int n = nxt();
		string a,b;
		cin >> a >> b;
		vector<int> diff;
		for(int i=0;i<n;i++) if(a[i] != b[i]) diff.pb(i);
		if(diff.size() == 0) {
			printf("YES\n");
		} else if(diff.size() == 2 && (a[diff[0]] == a[diff[1]] && b[diff[0]] == b[diff[1]])) {
			printf("YES\n");
		} else printf("NO\n");
	}

	return 0;

}



