#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
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
#define sep() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 100100

int v[N];

int main () {

	int t;

	cin >> t;

	while(t--) {
		int n;
		cin >> n;
		int s = 0;
		FOR(i,0,n) {
			cin >> v[i];
			s += v[i];
		}

		FOR(i,0,n) {
			if(v[i] > s/2) {
				printf("T\n");
				goto fini;
			}
		}
		
		if(s % 2 == 0) {
			printf("HL\n");
		} else printf("T\n");

fini:;

	}


	return 0;

}



