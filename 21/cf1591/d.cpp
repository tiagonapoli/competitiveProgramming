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
#define N 500100

int v[N];
int pos[N];
int n;


bool check() {
	if(n == 1) return true;
	if(n == 2 && v[1] <= v[2]) return true;

	for(int i=0; i<3; i++) {
		if(v[1] <= v[2] && v[2] <= v[3]) return true;
		swap(v[2], v[3]);
		swap(v[1], v[2]);
	}

	return false;
}

void sw(int a, int b) {
	swap(pos[v[a]], pos[v[b]]);
	swap(v[a], v[b]);
}

int main () {

	int t = nxt();

	while(t--) {
		n = nxt();

		for(int i=0;i<=n;i++) pos[i] = -1;

		bool equals = 0;
		for(int i=1;i<=n;i++) {
			v[i] = nxt();
			if(pos[v[i]] != -1) {
				equals = 1;
			}

			pos[v[i]] = i;
		}

		if(equals && (n > 3)) {
			printf("YES\n");
			continue;
		}

		for(int i=n;i>=4;i--) {
			if(v[i] != i) {
				if(pos[i] == 1) {
					sw(2, 3);				
				} else if(pos[i] == 2) {
					sw(1, 3);
				} else sw(1, 2);
				
				sw(i, pos[i]);
			}

			if(debug) {
				for(int j=1;j<=n;j++) printf("%d ", v[j]);
				sepd();
			}
		}

		if(check()) {
			printf("YES\n");
		} else printf("NO\n");
	}

	return 0;

}



