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
int nxt() { int x; scanf("%d", &x); return x; }
#define N 100100

int n;
int v[N];

int main () {

	n = nxt();
	vector<int> id(n);
	iota(all(id), 1);
	set<int> missing(all(id));

	vector<int> res;	

	while(id.size() > 1) {
		int el1, el2;
		el1 = id[id.size()-1];
		el2 = id[id.size()-2];
		printf("? %d %d\n", el1, el2);
		fflush(stdout);
		int a = nxt();
		printf("? %d %d\n", el2, el1);
		fflush(stdout);
		int b = nxt();
		if(a < b) {
			v[el2] = b;
			id.erase(id.end()-2);
			missing.erase(b);
		} else {
			v[el1] = a;
			id.erase(id.end()-1);
			missing.erase(a);
		}
	}


	For(i,1,n+1) { 
		if(v[i] == 0) {
			v[i] = *missing.begin();
			break;
		}
	}

	printf("! ");
	For(i,1,n+1) {
		printf("%d ", v[i]);
	}
	printf("\n");
	fflush(stdout);

	return 0;

}



