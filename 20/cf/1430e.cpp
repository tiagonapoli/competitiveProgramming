#include "bits/stdc++.h"
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

#ifdef DEBUG
	const bool debug = 1;
#else
	const bool debug = 0;
#endif

#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define sep() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 300100

int bit[N];

int qry(int id) {
	int res = 0;
	while(id > 0) {
		res += bit[id];
		id -= id & (-id);
	}
	return res;
}

void upd(int id, int val) {	
	while(id < N) {
		bit[id] += val;
		id += id & (-id);
	}
}

void rangeupd(int a, int b, int val) {
	upd(a,val);
	upd(b+1,-val);
}

queue<int> alp[30];

int main () {

	int n = nxt();
	string s;
	cin >> s;
	For(i,1,n+1) {
		int c = s[i-1] - 'a';
		alp[c].push(i);
	}
	
	reverse(s.begin(), s.end());
	ll res = 0;
	For(i,1,n+1) {
		int c = s[i-1] - 'a';
		int now = alp[c].front();
		alp[c].pop();
		int pos = now + qry(now);
		res += pos - i;
		rangeupd(1,now,1);
	}

	printf("%lld\n", res);
	
	return 0;

}



