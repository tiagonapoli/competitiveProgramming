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

int ask(int a, int b, int c) {
	printf("%d %d %d", a, b, c);
	fflush(stdout);
	return nxt();
}

vector<vector<int>>> v[2];
bool solved[N];
bool r[N];
int n;

void crewmateImposter(int a, int b) {
	for(int i=1;i<=n;i++) {

	}
}

int main () {

	n = nxt();

	for(int i=1;i<n;i+=3) {
		vector<int> a;
		a.pb(i);
		a.pb(i+1);
		a.pb(i+2);
		v[ask(i, i+1, i+2)].pb(a);
	}

	int a = ask(v[0][0][0], v[0][0][1], v[1][0][0]);
	int b = ask(v[0][0][0], v[0][0][1], v[1][0][1]);
	int c = ask(v[0][0][0], v[0][0][1], v[1][0][2]);

	if(a == 0 && b == 0 && c == 0) {
		solved[v[0][0][0]] = 1;
		solved[v[0][0][1]] = 1;
		r[v[0][0][0]] = 0;
		r[v[0][0][1]] = 0;


	} else {

	}
	

	return 0;

}



