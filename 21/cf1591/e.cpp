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
#define N 1001000

struct rangeInfo {
	int begin, end;

	int size() {
		return end - begin + 1;
	}

	void removeFromEnd() {
		assert(size() > 0);
		end--;
	}

	void addToEnd(int pos) {
		if(size() == 0) {
			begin = end = pos;
			return;	
		}

		end++;
		assert(end == pos);
	}

	void removeFromBeginning() {
		assert(size() > 0);
		begin++;
	}

	void addToBegin(int pos) {
		if(size() == 0) {
			begin = end = pos;
			return;
		}

		begin--;
		assert(begin == pos);
	}
};

pii cnt[N];
rangeInfo ranges[N];
int numberPos[N];

struct DataStruct {
	int n;

	DataStruct(int n) {
		this->n = n;
		ranges[0] = {1, n};
		for(int i=1;i<=n;i++) {
			cnt[i] = {0, i};
			numberPos[i] = i;
			ranges[i] = {0, -1};
		}
	}

	void swapNumbers(int x, int y) {
		swap(cnt[numberPos[x]], cnt[numberPos[y]]);
		swap(numberPos[x], numberPos[y]);
	}

	void print() {
		if(!debug) return;
		for(int i=1;i<=n;i++) {
			printf("%d/%d ", cnt[i].fi, cnt[i].se);
		}
		sepd();

		for(int i=1;i<=n;i++) {
			printf("[%d]:%d 	", i, numberPos[i]);
		}
		sepd();

		for(int i=0;i<=n;i++) {
			printf("%d:%d->%d ", i, ranges[i].begin, ranges[i].end);
		}
		sepd();
		
	}

	void incrementNumberCount(int number) {
		if(debug) printf("Increment %d\n", number);
		

		int p = numberPos[number];
		swapNumbers(number, cnt[ranges[cnt[p].fi].end].se);

		p = numberPos[number];
		ranges[cnt[p].fi].removeFromEnd();
		cnt[p].fi++;
		ranges[cnt[p].fi].addToBegin(p);

		print();
	}

	void decrementNumberCount(int number) {
		if(debug) printf("Decrement %d\n", number);
		int p = numberPos[number];
		swapNumbers(number, cnt[ranges[cnt[p].fi].begin].se);

		p = numberPos[number];
		ranges[cnt[p].fi].removeFromBeginning();
		cnt[p].fi--;
		ranges[cnt[p].fi].addToEnd(p);
		print();
	}

	int cntLowerBound(int l) {
		int i = 1, f = n+1;
		while(f > i) {
			int m = (i + f) / 2;
			if(cnt[m].fi >= l) {
				f = m;
			} else i = m+1;
		}

		return f;
	}

	int query(int l, int k) {
		if(debug) printf("Query %d %d\n", l, k);
		int pos = cntLowerBound(l);
		prin(pos);
		pos += k - 1;
		prin(pos);
		sepd();
		if(pos <= n) {
			return cnt[pos].se;
		}

		return -1;
	}
};

vector<pair<int, pii>> queries[N];
int responses[N];
vector<int> adj[N];
int v[N];
void dfs(int u, int p, DataStruct& s) {
	sepd();
	prin(u);
	s.incrementNumberCount(v[u]);
	
	for(auto q : queries[u]) {

		 responses[q.fi] = s.query(q.se.fi, q.se.se);
	}

	for(int x : adj[u]) {
		if(x == p) continue;
		dfs(x, u, s);
	}

	s.decrementNumberCount(v[u]);
	sepd();
}

int main () {

	int t = nxt();

	while(t--) {
		int n = nxt();
		DataStruct s(n);
		for(int i=0;i<=n;i++) {
			adj[i].clear();
			queries[i].clear();
		}

		int q = nxt();
		for(int i=1;i<=n;i++) {
			v[i] = nxt();
		}

		for(int i=2;i<=n;i++) {
			int p = nxt();
			adj[i].pb(p);
			adj[p].pb(i);
		}

		int a, b, c;
		for(int i=0;i<q;i++) {
			a = nxt();
			b = nxt();
			c = nxt();
			queries[a].pb({i, {b, c}});
		}

		dfs(1, -1, s);
		for(int i=0;i<q;i++) printf("%d ", responses[i]);
		printf("\n");
	}


	return 0;

}



