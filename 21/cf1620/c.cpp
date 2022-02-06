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


int main () {

	int t = nxt();

	while(t--) {
		int n, k;
		ll x;
		cin >> n >> k >> x;
		x--;
		vector<ll> v;

		string s;
		cin >> s;

		for(int i=0;i<n;i++) {
			if(s[i] == 'a') continue;
			if(i-1 >= 0 && s[i-1] == '*') {
				v[v.size()-1]+=k;
			} else v.pb(k);
		}

		if(v.size() == 0) {
			cout << s << endl;
			continue;
		}

		for(int i=(int)v.size()-1;i>=0;i--) {
			v[i]++;
			ll aux = x % v[i];
			x /= v[i];
			v[i] = aux;
			prin(v[i]);
		}

		string res;
		int j = 0;
		for(int i=0;i<n;i++) {
			if(s[i] == 'a') {
				res.pb('a');
				continue;
			}

			while(v[j] > 0) {
				res.pb('b');
				v[j]--;
			}

			j++;

			while(s[i] == '*' && i+1 < n && s[i+1] == '*') {
				i++;
			}
		}

		cout << res << endl;

	}

	return 0;

}



