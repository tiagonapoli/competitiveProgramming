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
inline int nxtll() { ll x; scanf("%lld", &x); return x; }
#define N 500100

char color[N];
bool compare (vector<int> &i, vector<int> &j) { return i[1] > j[1]; }

vector<vector<int>> createVector(int n, int m, int init = 0) {
	vector<vector<int>> r(n+2);
	for(int i=0;i<n+2;i++) r[i] = vector<int>(m+2);
	for(int i=0;i<n+2;i++) for(int j=0;j<m+2;j++) r[i][j] = init;
	return r;
}

void print(vector<vector<int>> &v, int n, int m) {
	if(!debug) return;
	for(int i=0;i<=n+1;i++) {
		for(int j=0;j<=m+1;j++) {
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		int m = nxt();
		vector<vector<int>> v = createVector(n, m);
		for(int i=1;i<=n;i++) {
			v[i][0] = i;
			for(int j=1;j<=m;j++) {
				v[i][j] = nxt();
			}
		}

		sort(v.begin()+1, v.end()-1, compare);

		print(v, n, m);

		vector<vector<int>> upperPref, lowerPref, upperSuf, lowerSuf;
		upperPref = createVector(n,m, 10000000);
		lowerPref = createVector(n,m, 0);
		upperSuf = createVector(n,m, 0);
		lowerSuf = createVector(n,m, 10000000);

		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) upperPref[i][j] = min(v[i][j], min(upperPref[i-1][j], upperPref[i][j-1])); 
		for(int i=n;i>=1;i--) for(int j=1;j<=m;j++) lowerPref[i][j] = max(v[i][j], max(lowerPref[i+1][j], lowerPref[i][j-1])); 
		for(int i=1;i<=n;i++) for(int j=m;j>=1;j--) upperSuf[i][j] = max(v[i][j], max(upperSuf[i-1][j], upperSuf[i][j+1])); 
		for(int i=n;i>=1;i--) for(int j=m;j>=1;j--) lowerSuf[i][j] = min(v[i][j], min(lowerSuf[i+1][j], lowerSuf[i][j+1])); 

		// print(upperPref, n, m);
		// print(lowerPref, n, m);
		// print(upperSuf, n, m);
		// print(lowerSuf, n, m);

		for(int i=1;i<=n;i++) color[i] = 'B';

		for(int i=1;i<n;i++) {
			color[v[i][0]] = 'R';
			for(int j=1;j<m;j++) {
				if(debug) printf("TRY %d %d\n", i, j);
				if(upperPref[i][j] > lowerPref[i+1][j] && upperSuf[i][j+1] < lowerSuf[i+1][j+1]) {
					printf("YES\n");
					for(int k=1;k<=n;k++) printf("%c", color[k]);
					printf(" %d\n", j);
					goto end;
				}
			}
		}
		
		printf("NO\n");
		end:;
	}

	return 0;

}



