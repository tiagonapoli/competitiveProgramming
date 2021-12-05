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

string s;

bool isAbc(int p) {
	if(p + 2 >= (int) s.size()) return 0;
	if(p < 0) return 0;
	return s[p] == 'a' && s[p+1] == 'b' && s[p+2] == 'c';
}

int main () {

	int n = nxt();
	int q = nxt();
	cin >> s;

	int r = 0;
	for(int i=0;i<n;i++) {
		r += isAbc(i);
	}

	while(q--) {
		int pos;
		char c;
		scanf("%d %c", &pos, &c);
		pos--;
		
		for(int i=-2;i<=2;i++) {
			r -= isAbc(pos + i);
		}

		s[pos] = c;

		for(int i=-2;i<=2;i++) {
			r += isAbc(pos + i);
		}

		printf("%d\n", r);
	}

	return 0;

}



