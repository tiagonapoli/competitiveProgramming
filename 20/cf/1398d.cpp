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

ll dp[210][210][210];
vector<int> v[3];

ll solve(int a, int b, int c) {
	if(dp[a][b][c] != -1) return dp[a][b][c];
	ll &r = dp[a][b][c];
	r = 0;
	if(a < v[0].size()) {
		if(b < v[1].size()) r = max(r, v[0][a]*v[1][b] + solve(a+1,b+1,c));
		if(c < v[2].size()) r = max(r, v[0][a]*v[2][c] + solve(a+1,b,c+1));
	}

	if(b < v[1].size() && c < v[2].size()) r = max(r, v[1][b]*v[2][c] + solve(a,b+1,c+1));
	return r;
}


int main () {


	int n[3];
	cin >> n[0] >> n[1] >> n[2];
	int x;
	for(int j=0;j<3;j++) {
		for(int i=0;i<n[j];i++) {
			scanf("%d", &x);
			v[j].pb(x);	
		}
		sort(v[j].begin(), v[j].end(), greater<int>());
	}

	for(int i=0;i<=200;i++) {
		for(int j=0;j<=200;j++) {
			for(int k=0;k<=200;k++) dp[i][j][k] = -1;
		}
	}

	printf("%lld\n", solve(0,0,0));
	return 0;

}



