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

int v[N];
int v1[N];

int main () {

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int mini;
		for(int i=0;i<n;i++) {
			scanf("%d", &v[i]);
			v1[i] = v[i];
			if(i==0 || mini > v[i]) mini = v[i];
		}

		sort(v,v+n);

		for(int i=0;i<n;i++) {
			if(v[i] != v1[i] && v1[i] % mini != 0) {
				printf("NO\n");
				goto done;
			}
		}

		printf("YES\n");
done:;
	}


	return 0;

}



