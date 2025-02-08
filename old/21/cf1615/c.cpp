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

string inverse(string &a, string b) {
	string r;
	for(int i=0;i<a.size();i++) {
		r.pb(a[i] == '0' ? '1' : '0'); 
	}

	for(int i=0;i<b.size();i++) {
		if(r[i] != b[i]) {
			r[i] = b[i];
			break;
		}
	}

	return r;
}

int diff(string a, string b) {
	int cnt =0;
	for(int i=0;i<a.size();i++) {
		if(a[i] != b[i]) cnt++; 
	}

	return cnt;
}

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		string a, b;
		cin >> a >> b;

		int u1, u2;
		u1 = u2 = 0;
		for(int i=0;i<n;i++) {
			if(a[i] == '1') {
				u1++;
			}

			if(b[i] == '1') {
				u2++;
			}
		}

		int u1inverse = n - u1 + 1;
		if(u1 != u2 && u1inverse != u2) {
			printf("-1\n");
			continue;
		}

		int res;
		if(u1 == u2 && u1inverse == u2) {
			res = min(diff(a, b), 1 + diff(inverse(a, b), b));
		} else if(u1 == u2) {
			res = diff(a,b);
		} else {
			res = 1 + diff(inverse(a, b), b);
		}

		printf("%d\n", res);
	}

	return 0;

}



