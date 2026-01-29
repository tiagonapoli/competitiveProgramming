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
#define N 8100

char str[N];
int ini;
int sz;
vector<string> parts;

int main () {

	int t = nxt();
	while(t--) {
		int n = nxt();
		parts.clear();
		for (int i = 0; i < n; i++) {
			parts.pb("");
			cin >> parts.back();
		}

		ini = 4000;
		sz = (int)parts[0].size();
		for (int i=0;i<sz;i++) {
			str[ini+i] = parts[0][i];
		}

		for (int i=1;i<(int)parts.size(); i++) {

			// add to the beginning and end
			for (int j=0;j<(int)parts[i].size();j++) {
				assert(ini - parts[i].size() + j >= 0);
				assert(sz + j < N);
				str[ini - parts[i].size() + j] = parts[i][j];
				str[ini + sz + j] = parts[i][j];
			}

			// now create 2 string_views and compare them
			sz += parts[i].size();
			string_view beg{str+ini-parts[i].size(), sz};
			string_view end{str+ini, sz};
			if(debug) {
				cout << beg << endl << end << endl;
				prin(ini);
				prin(sz);
				sep();
			}

			if (beg <= end) {
				ini -= parts[i].size();
			}
		}

		string_view full{str+ini, sz};
		cout << full;
		sep();
	}

	return 0;

}

