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
inline ll nxtll() { ll x; scanf("%lld", &x); return x; }
#define N 100100

int findNext1(string_view str, int offset) {
	for (int i=offset;i<str.size(); i++) {
		if (str[i] == '1') return i;
	}

	return -1;
}

void reverseDigits(string& str, int a, int b) {
	for (int i=a;i<=b;i++) {
		str[i] = str[i] == '0' ? '1' : '0';
	}
}

std::vector<pii> opsToGetToZero(string& str) {
	std::vector<pii> ret;

	for (int i=0;i<str.size(); i++) {
		if (str[i] == '0') continue;

		int next1 = findNext1(str, i+1);
		if (next1 != -1) {
			reverseDigits(str, i, next1);
			ret.pb({ i+1, next1+1 });
			continue;
		}

		// Either there will be 2 zeros forward or 2 zeros back, let's identify the case
		if (i + 2 < str.size()) {
			ret.pb({ i+2, i+3 });
			ret.pb({ i+1, i+3 });
		} else {
			assert(i >= 2);
			ret.pb({ i-1, i });
			ret.pb({ i-1, i+1 });
		}

		break;
	}

	return ret;

}

int main () {

	int t = nxt();
	while(t--) {
		int n = nxt();
		string source, target;
		cin >> source >> target;
		
		if (source == target) {
			printf("0\n");
			continue;
		}

		vector<pii> ret1 = opsToGetToZero(source);
		vector<pii> ret2 = opsToGetToZero(target);
		reverse(ret2.begin(), ret2.end());

		if (debug) {
			for (auto p : ret1) {
				printf("%d %d\n", p.fi, p.se);
			}

			printf("\n\n");

			for (auto p : ret2) {
				printf("%d %d\n", p.fi, p.se);
			}
		}

		
		printf("%d\n", ret1.size() + ret2.size());
		for (auto p : ret1) {
			printf("%d %d\n", p.fi, p.se);
		}

		for (auto p : ret2) {
			printf("%d %d\n", p.fi, p.se);
		}
	}


	return 0;

}

