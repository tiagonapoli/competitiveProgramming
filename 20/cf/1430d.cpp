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
#define N 200100

string v[N];

int n;
int qtd;
void updnxt(int &p) {
	for(;p<qtd && v[p].size() <= 1;p++) {}
}

int main () {

	int t = nxt();
	while(t--) {
		n = nxt();
		string s;
		cin >> s;
		qtd = 0;
		for(int i=0;i<n;) {
			int j;
			for(j=i;j<n && s[j] == s[i];j++) {
				v[qtd].pb(s[j]);
			}
			i = j;
			qtd++;
		}

		prin(qtd);
		For(i,0,qtd) prin(v[i]);

		int ops = 0;
		int p = 0;
		For(i,0,qtd) {
			if(v[i].size() == 0) continue;
			updnxt(p);
			prin(i);
			prin(v[i]);
			prin(p);
			if(p >= qtd) {
				v[i].pop_back();
				i++;
				while(i < qtd && v[i].size() == 0) i++;
				prin(i);
				prin(v[i]);
				if(i < qtd && v[i].size() > 0) v[i].pop_back();
			} else {
				v[p].pop_back();
				v[i] = "";
			}
			ops++;
			sep();
		}

		printf("%d\n", ops);
	}


	return 0;

}



