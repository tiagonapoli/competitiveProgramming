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

int a[N];
int solve(int l, int r, int h) {
	//printf("%d -> %d [%d]\n", l, r, h);
	if(l > r) return 0;

	int mini = a[l];
	for(int i=l;i<=r;i++) {
		mini = min(mini, a[i]);
	}

	int res = mini - h;
	vector<int> v;
	for(int i=l;i<=r;i++) {
		if(a[i] == mini) v.pb(i);
	}

	res += solve(l, v[0]-1, mini);
	res += solve(v.back()+1, r, mini);
	for(int i=0;i<v.size()-1;i++) {
		res += solve(v[i]+1, v[i+1]-1, mini);
	}
	
	return min(res, r-l+1);
	
}


int main () {

	int n;

	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}

	printf("%d\n", min(n, solve(0,n-1, 0)));

	return 0;

}



