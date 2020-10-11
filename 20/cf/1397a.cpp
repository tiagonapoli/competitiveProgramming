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

int cnt[30];

int main () {

	int t;
	int n;

	cin >> t;

	while(t--) {
		cin >> n;
		string s;
		
		for(int i=0;i<30;i++) cnt[i] = 0;

		for(int i=0;i<n;i++) {
			cin >> s;
			for(char c : s) {
				cnt[c - 'a']++;
			}
		}

		for(int i=0;i<30;i++) {
			if(cnt[i] % n != 0) {
				printf("NO\n");
				goto fini;
			}
		}

		printf("YES\n");
fini:;
	}



	return 0;

}



