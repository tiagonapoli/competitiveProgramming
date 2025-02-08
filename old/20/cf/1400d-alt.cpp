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
#define N 3123

int v[N];
ll cntLeft[N];
ll cntRight[N];

int main () {

	int t;
	
	cin >> t;

	int n;
	while(t--) {
		scanf("%d", &n);

		for(int i=0;i<=n;i++) {
			cntRight[i] = cntLeft[i] = 0;
		}

		for(int i=0;i<n;i++) {
			scanf("%d", &v[i]);
		}

		ll res = 0;
		for(int j=0;j<n;j++) {
			for(int k=n-1;k>j;k--) {
				res += cntLeft[v[k]] * cntRight[v[j]];
				cntRight[v[k]]++;
			}

			cntLeft[v[j]]++;
			for(int k=0;k<=n;k++) {
				cntRight[k] = 0;
			}
		}

		cout << res << endl;
	}


	return 0;

}



