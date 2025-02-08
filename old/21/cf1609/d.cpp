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

int f[N];
int sz[N];
int r[N];
int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(r[a] <= r[b]) swap(a,b);
	if(r[a] == r[b]) r[a]++;
	
	f[b] = a;
	sz[a] += sz[b];
	sz[b] = 0;
}

int sz2[N];
int main () {
	int n = nxt();
	int m = nxt();

	for(int i=0;i<=n;i++) {
		f[i] = i;
		sz[i] = 1;
		r[i] = 0;
	}

	int open = 1;
	while(m--) {
		int a = nxt();
		int b = nxt();
		a--;
		b--;
			
		if(find(a) == find(b)) open++;
		join(a,b);

		for(int j=0;j<n;j++) {
			sz2[j] = sz[j];
		}

		sort(sz2, sz2+n, greater<int>());
		int res = 0;
		for(int i=0;i<open;i++) {
			res += sz2[i];
		}

		printf("%d\n", res - 1);
	}

	return 0;

}



