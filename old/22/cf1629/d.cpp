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
inline int nxtll() { ll x; scanf("%lld", &x); return x; }
#define N 100100

string v[N];

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();

		set<string> inv, suff3;

		for(int i=0;i<n;i++) {
			cin >> v[i];
		}

		for(int i=n-1;i>=0;i--) {
			string b = string(v[i].rbegin(), v[i].rend());
			inv.insert(b);

			if(inv.find(v[i]) != inv.end() || (v[i].size() == 2 && suff3.find(v[i]) != suff3.end())) {
				printf("YES\n");
				goto fim;
			}

			if(v[i].size() == 3) {
				string ini = string(v[i].begin(), v[i].end()-1);
				prin(ini);
				if(inv.find(ini) != inv.end()) {
					printf("YES\n");
					goto fim;
				}

				string end = string(v[i].rbegin(), v[i].rend()-1);
				suff3.insert(end);
				prin(end);
			}
		}

		for(auto &el : inv) {
			prin(el);
		}

		printf("NO\n");
		fim:;
	}

	return 0;

}



