#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

bool debug = 1;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define separa() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 100100

int sz = 0;

int main () {

	string s;
	int t;

	cin >> t;
	while(t--) {
		cin >> s;
		vector<int> v;
		

		for(int i=0;i<s.size();) {
			if(s[i] == '0') {
				++i;
				continue;
			}
			int j=i;
			for(; j<s.size() && s[j] == '1';j++) {}
			v.pb(j-i);
			i=j;
		}
		
		sort(v.begin(), v.end());
		int c = 0;
		int a, b;
		a = b = 0;
		for(int i=v.size()-1;i>=0;i--) {
			if(c % 2 == 0) {
				a+=v[i];
			} else b+=v[i];
			c++;
		}

		printf("%d\n", a);
	}


	return 0;

}



