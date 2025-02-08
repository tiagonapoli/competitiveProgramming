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

string s;

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		cin >> s;

		int zeroes = 0;
		for(int i=0;i<n;i++) {
			if(s[i] == '0') {
				zeroes++;
			}
		}

		vector<int> r;
		for(int i=0;i<zeroes;i++) {
			if(s[i] == '1') r.pb(i + 1);
		}

		for(int i=zeroes; i<n;i++) {
			if(s[i] == '0') r.pb(i+1);
		}

		if(r.size() == 0) {
			printf("0\n");
			continue;
		}

		printf("1\n%d ", (int)r.size());
		for(int x : r) {
			printf("%d ", x);
		}

		printf("\n");	
	}

	return 0;

}



