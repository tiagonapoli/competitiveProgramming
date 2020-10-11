#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

bool debug = 1;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define separa() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 100100


int main () {
	
	int t;

	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		if(k >=n) {
			printf("%d\n", k-n);
			continue;
		} else if(n % 2 == k % 2) {
			printf("0\n");
		} else printf("1\n");
	}



	return 0;

}



