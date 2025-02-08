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
#define sep() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
int nxt() { int x; cin >> x; return x; }
#define N 100100

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		int k = nxt();
		string s;
		cin >> s;

		int one, zero, quest;
		one = zero = quest = 0;
		For(i,0,k) {
			char res = '?';
			for(int j=i;j<n;j+=k) {
				if(s[j] == '?') continue;
				if(res == '?') {
					res = s[j];
				} else if(res != s[j]) {
					printf("NO\n");
					goto fini;
				}
			}

			s[i] = res;
			if(res == '1') {
				one++;
			} else if(res == '0') {
				zero++;
			} else quest++;
		}

		if(one > k/2 || zero > k/2) {
			printf("NO\n");
		} else printf("YES\n");

fini:;

	}


	return 0;

}



