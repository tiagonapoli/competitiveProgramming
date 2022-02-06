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

ll d[N];

int n1;
int negative[N];

int n2;
int positive[N];

pair<ll, ll> solve(int *v, int n, int k) {
	
	d[0] = 0;
	for(int i=1;i<n;i++) {
		int from = max(0, i - k);
		d[i] = d[from] + v[from] + v[i]; 
	}

	return {d[n-1], v[n-1]};
}


int main () {

	int t = nxt();



	while(t--) {
		int n = nxt();
		int k = nxt();

		n1 = 1;
		n2 = 1;
		negative[0] = positive[0] = 0;
		for(int i=0;i<n;i++) {
			int x = nxt();
			if(x == 0) continue;
			if(x < 0) {
				negative[n1++] = -x;
			} else positive[n2++] = x;
		}

		sort(negative, negative + n1);
		sort(positive, positive + n2);

		pair<ll, ll> r1 = solve(negative, n1, k);
		pair<ll, ll> r2 = solve(positive, n2, k);

		printf("%lld\n", r1.fi + r2.fi + min(r1.se, r2.se));
	}

	return 0;

}



