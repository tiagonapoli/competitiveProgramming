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

int pot2[32];

int main () {

	pot2[0] = 1;
	for(int i=1;i<=30;i++) {
		pot2[i] = pot2[i-1] * 2;	
	}

	int t = nxt();
	while(t--) {
		int n = nxt();
		if(n % 2 == 1) {
			printf("Bob\n");
		} else if(__builtin_popcount(n) == 1) {
			int i = 0;
			while(n > 1) {
				n /= 2;
				i++;
			}

			if(i % 2 == 1) {
				printf("Bob\n");
			} else printf("Alice\n");
		} else printf("Alice\n");
	}

	return 0;

}



