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
#define sepd() if(debug) cout << endl
#define sep() printf("\n");

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 100100


int main () {

	int n = nxt();

	int lo = 1;
	int hi = 1 + 1e9;
	int black = -1;
	int white = -1;

	string first;
	cout << 0 << " " << 0 << endl;
	cin >> first;
	white = 0;
	n--;

	string s;
	while(lo <= hi && n) {
		prin(n);
		n--;
		int mid = (lo+hi)/2;
		cout << 0 << " " << mid << endl;
		cin >> s;
		if(s == first) {
			lo = mid+1;
			white = mid;
		} else {
			hi = mid-1;
			black = mid;
		}
	}

	prin(black);
	prin(white);
	if(white == -1 || black == -1) {
		printf("1 0 1 1\n");
	} else {
		int b = (black + white);
		if(b/2 + 2 > 1e9) {
			printf("1 %d 3 %d\n", b/2-1, b/2-2);
		} else {
			printf("1 %d 3 %d\n", b/2+1, b/2+2);
		}
	}
	return 0;

}



