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

int v[N];
vector<int> neg;
vector<int> pos;

int main () {
	int t = nxt();

	while(t--) {
		int n = nxt();
		For(i,0,n) {
			v[i] = nxt();
		}
		
		int j = n-1;
		ll cost = 0;
		for(int i=n-1;i>=0;i--) {
			if(v[i] >= 0) {
				cost += v[i];
				continue;
			}

			prin(i);
			prin(v[i]);

			j = min(j, i-1);
			while(v[i] < 0 && j >= 0) {
				if(v[j] < 0) {
					j--;
					continue;
				}

				if(abs(v[i]) <= abs(v[j])) {
					v[j] -= abs(v[i]);
					v[i] = 0;
					break;
				} else {
					v[i] += abs(v[j]);
					v[j] = 0;
				}

				sep();
				j--;
			}

			sep();
		}

		printf("%lld\n", cost);
	}


	return 0;

}



