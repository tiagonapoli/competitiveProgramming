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
#define N 100100
#define MAX 1000

ll dp[20001];
ll c[1010];
int b[1010], d[1010];

void bfs(int x) {

	queue<int> q;
	d[x] = 0;
	q.push(x);
	
	while(!q.empty()) {
		
		int x = q.front();
		q.pop();

		for(int i=1;i*i <= x; i++) {
			int nxt = x + x/i;
			if(nxt <= MAX && d[nxt] == 0) {
				d[nxt] = d[x] + 1;
				q.push(nxt);
			}

			nxt = x + x/(x/i);
			if(nxt <= MAX && d[nxt] == 0) {
				d[nxt] = d[x] + 1;
				q.push(nxt);
			}
		}
	}
}

int main () {

	bfs(1);
	int t = nxt();
	while(t--) {
		
		int n = nxt();
		int k = nxt();
		for(int i=0;i<n;i++) b[i] = nxt();
		for(int i=0;i<n;i++) c[i] = nxt();

		k = min(k, 15000);
		for(int i=0;i<=k;i++) dp[i] = -1;
		dp[0] = 0;

		for(int i=0;i<n;i++) {
			for(int j=k-d[b[i]];j>=0;j--) {
				if(dp[j] == -1LL) continue;
				int nxt = j + d[b[i]];
				dp[nxt] = max(dp[nxt], dp[j] + c[i]);
			}
		}

		ll res = 0;
		for(int i=0;i<=k;i++) res = max(res, dp[i]);
		printf("%lld\n", res);
	}
	

	return 0;

}



