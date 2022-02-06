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
#define N 500100

int p[N];
vector<array<int, 3>> queries;
vector<int> v;

int main () {

	int q = nxt();

	for(int i=0;i<N;i++) {
		p[i] = i;
	}

	For(i,0,q) {
		int a = nxt();
		if(a == 1) {
			int x = nxt();
			queries.pb({1, x, 0});
			v.pb(x);
		} else {
			int x = nxt(), y = nxt();
			queries.pb({2, x, y});
		}
	}


	int j = v.size()-1;
	for(int i=queries.size()-1;i>=0;i--) {
		auto el = queries[i];
		if(el[0] == 1) {
			v[j] = p[v[j]];
			j--;
		} else {
			p[el[1]] = p[el[2]];
		}
	}

	for(int x : v) {
		printf("%d ", x);
	}

	sep();

	return 0;

}



