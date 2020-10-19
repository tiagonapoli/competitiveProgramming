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
int nxt() { int x; scanf("%d", &x); return x; }
#define N 100100

int v[N];
bool used[N];

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		For(i,0,n) used[i] = 0;
		generate(v,v+n,nxt);

		int maxid = 0;
		For(i,0,n) {
			if(v[i] > v[maxid]) maxid = i;
		}

		vector<int> res;
		int a = 0;
		For(i,0,n) {
			maxid = -1;
			for(int j=0;j<n;j++) {
				if(used[j]) continue;
				if(maxid == -1 || __gcd(v[j], a) > __gcd(a, v[maxid])) {
					maxid = j;
				}
			}

			res.pb(v[maxid]);
			used[maxid] = 1;
			a = __gcd(a, v[maxid]);
		}

		for(int x : res) printf("%d ", x);
		printf("\n");
		

	}


	return 0;

}



