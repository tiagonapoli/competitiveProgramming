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

vector<int> p;
bool composite[N];
void sieve() {
	for(int i=2;i<N;i++) {
		if(composite[i] == 0) {
			p.pb(i);
			for(int j=i;j<N;j+=i) composite[j] = 1;
		}
	}
}

int main () {


	sieve();
	int t = nxt();

	while(t--) {
		int n = nxt();

		if(n % 2 == 0) {
			printf("%d %d %d\n", n/2, n/2 - 1, 1);
			continue;
		}
		
		for(int x : p) {
			if((n - x - 1) % x == 0) continue;
			printf("%d %d %d\n", x, n - x - 1, 1);
			break;
		}
	}

	return 0;

}



