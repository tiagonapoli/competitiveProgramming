#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

bool debug = 0;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define separa() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 1001000

ll bit[N];

void upd(int id, ll val) {
	while(id < N) {
		bit[id] += val;
		id += id & (-id);
	}
}

ll qry(int id) {
	int sum = 0;
	while(id > 0) {
		sum += bit[id];
		id -= id & (-id);
	}
	return sum;
}

ll query(int a, int b) {
	return qry(b) - qry(a-1);
}

int OPEN_VTX = 0;
int PROC_SEG = 1;
int REM_VTX = 2;
int n,m;
map<int, set<pair<int, pii>>> events;

int maxi = 1000000+1;
int s[2][N][3];

ll sweep() {
	events.clear();
	for(int i=0;i<N;i++) bit[i] = 0;

	for(int i=0;i<n;i++) {
		events[s[0][i][1]].insert({OPEN_VTX, {s[0][i][1], s[0][i][0]}});
		events[s[0][i][2]].insert({REM_VTX, {s[0][i][2], s[0][i][0]}});
	}
	
	for(int i=0;i<m;i++) {
		events[s[1][i][0]].insert({PROC_SEG, {s[1][i][1], s[1][i][2]}});
	}

	ll res = 0;
	for(auto ycoord : events) {
		prin(ycoord.fi);
		for(auto ev : ycoord.se) {
			if(debug) printf("EV:%d  %d %d\n", ev.fi, ev.se.fi, ev.se.se);
			if(ev.fi == OPEN_VTX) {
				upd(ev.se.se, 1LL);
			} else if(ev.fi == REM_VTX) {
				upd(ev.se.se, -1LL);
			} else {
				res += query(ev.se.fi, ev.se.se);	
			}
		}
		separa();
	}

	return res;
}

void read(int &x, int &y, int &z) {
	scanf("%d %d %d", &x, &y, &z);
	x++;
	y++;
	z++;
}

int main () {

	scanf("%d %d", &n, &m);
	
	ll f = 1;
	for(int i=0;i<n;i++) {
		read(s[0][i][0], s[0][i][1], s[0][i][2]);
		if(s[0][i][1] == 1 && s[0][i][2] == maxi) {
			f++;
		}
	}

	for(int i=0;i<m;i++) {
		read(s[1][i][0], s[1][i][1], s[1][i][2]);
		if(s[1][i][1] == 1 && s[1][i][2] == maxi) {
			f++;
		}
	}
	
	prin(f);
	f += sweep();

	printf("%lld\n", f);
	
	return 0;

}



