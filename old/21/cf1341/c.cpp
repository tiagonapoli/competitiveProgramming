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

int v[N];

int sz[N];
int nextEmpty[N];
int findNextEmpty(int x) {
	if(nextEmpty[x] == x) return x;
	return nextEmpty[x] = findNextEmpty(nextEmpty[x]);
}

map<int, set<int>> positionsByCount;

void removeFromMap(int cnt, int pos) {
	positionsByCount[cnt].erase(pos);
	if(positionsByCount[cnt].size() == 0) {
		positionsByCount.erase(cnt);
	}
}

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		positionsByCount.clear();
		for(int i=0;i<n;i++) {
			sz[i] = 1;
			nextEmpty[i] = i;
			positionsByCount[1].insert(i);
		}

		nextEmpty[n] = n;

		for(int i=0;i<n;i++) {
			int x = nxt();
			v[x] = i;
		}

		for(int i=1;i<=n;i++) {
			auto maxCountPair = positionsByCount.rbegin();
			if(debug) {
				printf("position %d\n", v[i]);
				printf("max count: %d\n", maxCountPair->fi);
			}
			
			if(maxCountPair->se.count(v[i]) == 0) {
				printf("No\n");
				goto fim;
			}

			removeFromMap(maxCountPair->fi, v[i]);

			int nxt = findNextEmpty(v[i] + 1);
			if(debug) printf("next empty %d\n", nxt);

			if(nxt != n) {
				removeFromMap(sz[nxt], nxt);
				sz[nxt] += sz[nextEmpty[v[i]]];
				positionsByCount[sz[nxt]].insert(nxt);
			}

			sz[nextEmpty[v[i]]] = 0;
			nextEmpty[v[i]] = nxt;

			sepd();
		}
		
		printf("Yes\n");

		fim:;
	}

	return 0;

}



