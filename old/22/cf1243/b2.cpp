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
inline ll nxtll() { ll x; scanf("%lld", &x); return x; }
#define N 100100

int cnt[30];


int main () {

	int k = nxt();

	while(k--) {
		for(int i=0;i<30;i++) cnt[i] = 0;

		int n = nxt();
		string a, b;
		cin >> a >> b;
		for(int i=0;i<n;i++) {
			cnt[a[i] - 'a']++;
			cnt[b[i] - 'a']++;
		}

		vector<pii> res;
		for(int i=0;i<30;i++) {
			if(cnt[i] % 2 == 1) {
				printf("No\n");
				goto fim;
			}
		}

		for(int i=0;i<n;i++) {
			if(a[i] == b[i]) continue;
			for(int j=i+1;j<n;j++) {
				if(a[j] == b[i]) {
					swap(a[j], b[j]);
					res.pb({j,j});
				}

				if(b[j] == b[i]) {
					swap(a[i], b[j]);
					res.pb({i, j});
					break;
				}
			}
		}

		printf("Yes\n");
		printf("%d\n", (int) res.size());
		for(auto el : res) {
			printf("%d %d\n", el.fi + 1, el.se + 1);
		}

		fim:;
	}

	return 0;

}



