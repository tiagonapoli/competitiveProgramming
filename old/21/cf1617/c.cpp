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

multiset<int> _free;

int get(int x) {
	auto el1 = _free.find(x);
	if(el1 != _free.end()) {
		_free.erase(el1);
		return 0;
	}

	auto el = _free.lower_bound(2*x + 1);
	if(el == _free.end()) {
		return -1;
	}

	_free.erase(el);
	return 1;
}

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		
		_free.clear();
		for(int i=0;i<n;i++) {
			_free.insert(nxt());
		}

		int res = 0;
		for(int i=n;i>=1;i--) {
			int r = get(i);
			if(r == -1) {
				res = -1;
				break;
			}

			res += r;
		}

		printf("%d\n", res);
	}

	return 0;

}



