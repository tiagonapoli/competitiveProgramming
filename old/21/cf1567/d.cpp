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
#define N 100100

int v[1000];
int pot[12];

int main () {

	pot[0] = 1;
	for(int i=1;i<12;i++) pot[i] = pot[i-1] * 10;

	int t = nxt();

	while(t--) {

		int s = nxt();
		int n = nxt();

		for(int i=0;i<n;i++) v[i] = 0;

		int p[12];
		int r = 1000000000;
		for(int i=9;i>=0;i--) {
			p[i] = s / r;
			s -= r * p[i];
			r /= 10;
		}

		// for(int i=0;i<10;i++) {
		// 	printf("%d: %d\n", i, p[i]);
		// }

		int cnt = 0;
		for(int i=0;i<=9;i++) cnt += p[i];
		// prin(cnt);

		while(cnt < n) {
			for(int i=1;i<=9;i++) {
				if(p[i] > 0) {
					p[i]--;
					p[i-1] += 10;
					cnt += 9;
					break;
				}
			}
		}

		for(int i=0;i<n;i++) {
			for(int j=0;j<=9;j++) {
				if(p[j] > 0) {
					v[i] = pot[j];
					p[j]--;
					break;
				}
			}
		}

		// if(debug) for(int i=0;i<n;i++) printf("%d ", v[i]);
		// sep();

		for(int i=0;i<10;i++) {
			v[0] += pot[i] * p[i];
		}

		for(int i=0;i<n;i++) printf("%d ", v[i]);
		printf("\n");
	}

	return 0;

}



