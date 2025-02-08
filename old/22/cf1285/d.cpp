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
inline int nxtll() { ll x; scanf("%lld", &x); return x; }
#define N 3200100

const int initialBit = 1<<30;

int cnt = 1;
int adj[N][2];

void add(int num) {
	int now = 1;
	int bit = initialBit;
	while(bit > 0) {
		bool x = num & bit;
		if(adj[now][x] == 0) {
			adj[now][x] = ++cnt;
		}

		now = adj[now][x];
		bit /= 2;
	}
}

void print(int now = 1, int bit = initialBit) {
	if(now == 0 || bit == 0) return;
	printf("[%d] %d: %d %d\n", bit, now, adj[now][0], adj[now][1]);
	bit /= 2;
	print(adj[now][0], bit);
	print(adj[now][1], bit);
}

int solve(int now = 1, int bit = initialBit) {
	if(bit == 0) return 0;
	prin(bit);
	prin(now);

	if(adj[now][0] != 0 && adj[now][1] != 0) {
		if(debug) printf("both\n");
		return bit + min(solve(adj[now][0], bit/2), solve(adj[now][1], bit/2));
	}

	if(debug) printf("single\n");
	if(adj[now][0] == 0) {
		return solve(adj[now][1], bit/2);
	} else return solve(adj[now][0], bit/2);
}

int main () {

	int n = nxt();

	while(n--) {
		add(nxt());	
	}
	
	if(debug) print();

	printf("%d\n", solve());

	return 0;

}



