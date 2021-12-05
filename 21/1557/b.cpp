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
#define N 300100

int v[N];
int ord[N];
map<int, int> pos;

int main () {

	int t = nxt();
	while(t--) {
		int n = nxt();
		int k = nxt();
		pos.clear();

		for(int i=0;i<n;i++) {
			v[i] = nxt();
			ord[i] = v[i];
		}

		sort(ord, ord+n);
		for(int i=0;i<n;i++) {
			pos[ord[i]] = i;
		}

		int credits = 0;
		for(int i=1;i<n;i++) {
			if(pos[v[i-1]] == pos[v[i]] - 1) credits++;
		}

		prin(credits);
		if(k >= n - credits) {
			printf("YES\n");
		} else printf("NO\n");
	}

	return 0;

}



