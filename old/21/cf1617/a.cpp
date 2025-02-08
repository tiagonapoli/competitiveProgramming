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

int cnt[30];

int main () {

	int t = nxt();

	while(t--) {
		string a, b;
		cin >> a >> b;

		for(int i=0;i<30;i++) cnt[i] = 0;
		for(int i=0;i<a.size();i++) {
			cnt[a[i] - 'a']++;
		}

		string r;
		if(b == "abc" && cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
			r.insert(r.end(), cnt[0], 'a');
			r.insert(r.end(), cnt[2], 'c');
			r.insert(r.end(), cnt[1], 'b');
			cnt[0] = cnt[1] = cnt[2] = 0;
		}

		for(int i=0;i<26;i++) {
			r.insert(r.end(), cnt[i], 'a' + i);
		}

		cout << r << endl;
	}

	return 0;

}



