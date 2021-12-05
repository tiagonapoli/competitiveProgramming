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
#define N 200100

int v[N];
map<int, int> cnt;

int main () {

	int t = nxt();
	while(t--) {
		cnt.clear();
		int n = nxt();
		For(i,0,n) {
			v[i] = nxt();
			cnt[v[i]]++;
		}

		sort(v, v+n);

		int mini = v[n-1] - v[0];
		for(int i=0;i<n-1;i++) {
			if(v[i+1] - v[i] < mini) mini = v[i+1] - v[i];
		}

		if(n == 2) {
			printf("%d %d\n", v[0], v[1]);
			continue;
		}

		for(int i=0;i<n-1;i++) {
			if(v[i+1] - v[i] == mini) {
				for(int j=i+1;j<n;j++) {
					printf("%d ", v[j]);
				}

				for(int j=0;j<=i;j++) {
					printf("%d ", v[j]);
				}

				break;
			}
		}

		printf("\n");
	}


	return 0;

}



