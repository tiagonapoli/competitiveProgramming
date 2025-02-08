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

bool canBe[N][2];
int v[N];

int main () {

	int t;
	cin >> t;

	while(t--) {
		int x;
		string s;
		cin >> s >> x;
		for(int i=0;i<s.size();i++) {
			canBe[i][0] = canBe[i][1] = 1;
			v[i] = s[i] - '0';
		}

		int n = s.size();
		vector<int> res;
		for(int i=0;i<n;i++) {
			if(i+x >= n && i-x < 0 && v[i] == 1) {
				printf("-1\n");
				goto fini;
			} else if(i + x >= n || i-x < 0) {
				if(i+x < n) {
					canBe[i+x][!v[i]] = 0;
				}

				if(i-x >= 0) {
					canBe[i-x][!v[i]] = 0;
				}
			} else if(v[i] == 0){
				canBe[i+x][1] = canBe[i-x][1] = 0;
			}
		}

		for(int i=0;i<n;i++) {
			if(canBe[i][0] == 0 && canBe[i][1] == 0) {
				printf("-1\n");
				goto fini;
			}

			if(canBe[i][1]) {
				res.pb(1);
			} else res.pb(0);
		}

		for(int i=0;i<n;i++) {
			if(i+x >= n || i-x < 0) continue;
			if(v[i] == 1 && res[i+x] == 0 && res[i-x] == 0) {
				printf("-1\n");
				goto fini;
			}
		}

		for(int k : res) printf("%d", k);
		printf("\n");

fini:;
	}


	return 0;

}



