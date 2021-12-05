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
#define N 200100

int lchain[N];
int rchain[N];

int v[N];

vector<int> primes;

const int X = 1000010;
bool p[X];

void sieve() {

	for(int i=0;i<X;i++) p[i] = 0;	
	p[1] = p[0] = 1;
	
	for(int i=2;i<X;i++) {
		if(p[i] == 0) {
			primes.pb(i);
			for(int j=2*i;j<X;j+=i) {
				p[j] = 1;
			}
		}
	}
}

bool isPrime(int x) {
	return binary_search(primes.begin(), primes.end(), x);
}

int n;

bool hasOne(int x) {
	if(x >= 0 && x < n) {
		return v[x] == 1;
	}

	return 0;
}

int main () {

	sieve();

	int t = nxt();

	while(t--) {

		n = nxt();
		int e = nxt();

		for(int i=0;i<n;i++) v[i] = nxt();

		for(int i=0;i<n;i++) {
			rchain[i] = lchain[i] = 0;
		}

		for(int i=0;i<n;i++) {
			if(v[i] == 1) {
				lchain[i] = 1;
				if(hasOne(i - e)) lchain[i] += lchain[i - e];
			}

			if(debug) {
				printf("%d ", lchain[i]);
			}
		}

		sepd();

		for(int i=n-1;i>=0;i--) {
			if(v[i] == 1){
				rchain[i] = 1;
				if(hasOne(i + e)) rchain[i] += rchain[i + e];
			}
		}

		if(debug) for(int i=0;i<n;i++) printf("%d ", rchain[i]);
		sepd();

		ll res = 0;
		for(int i=0;i<n;i++) {
			if(p[v[i]] == 1) continue;

			if(debug) printf("[%d] %d\n", i, v[i]);
			ll a = hasOne(i + e) ? rchain[i + e] : 0;
			ll b = hasOne(i - e) ? lchain[i - e] : 0;
			res += (a + 1) * (b + 1) - 1LL;
		}

		printf("%lld\n", res);
	}


	return 0;

}



