#include "bits/stdc++.h"
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

#ifdef DEBUG
	const bool debug = 1;
#else
	const bool debug = 0;
#endif

#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define sepd() if(debug) cout << endl
#define sep() printf("\n");

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 100100

string s;

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		cin >> s;
		bool midzero = 0;
		if(n % 2 == 1 && s[n/2] == '0') midzero = 1;

		int dist = 0;
		for(int i=0;i<n-i-1;i++) {
			if(s[i] != s[n-i-1]) dist++;
		}



		int zero = 0;
		for(int i=0;i<n;i++) if(s[i] == '0') zero++;
		prin(zero);
		prin(dist);
		prin(midzero);

		if(dist == 0) {
			if(zero % 2 == 0 || zero == 1) printf("BOB\n");
			else printf("ALICE\n");	
		} else if(dist == 1 && zero == 2 && midzero) {
			printf("DRAW\n");
		} else {
			printf("ALICE\n");
		}
	}


	return 0;

}



