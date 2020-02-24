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

ll modmul(ll a, ll b) { return (a * b) % MOD; }
ll modsum(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll modsub(ll a, ll b) { return (((a % MOD) + (b % MOD)) + MOD) % MOD; }

template <typename T> struct matrix {
	static const int MAXDIM = 100;

	int n,m;
	T mat[matrix::MAXDIM][matrix::MAXDIM];

	matrix(int n, int m) : n(n), m(m) { assert(n < MAXDIM && m < MAXDIM); }
	matrix() : n(0), m(0) {}
	
	static void writeIdent(matrix &I) {
		assert(I.n == I.m);
		FOR(i,0,I.n) FOR(j,0,I.m) {
			I.mat[i][j] = 0;
			if(i == j) I.mat[i][j] = 1;
		}
	}

	static matrix mul(matrix &a, matrix &b, matrix &r) {
		assert(a.m == b.n);
		r.n = a.n; r.m = b.m;
		FOR(i,0,a.n) FOR(j,0,b.m) {
			r.mat[i][j] = 0;
			FOR(k,0,a.m) 
				r.mat[i][j] = modsum(r.mat[i][j], modmul(a.mat[i][k], b.mat[k][j]));
		}
		return r;
	}
	
	static matrix pow(matrix &b, ll e, matrix &raux) {
		assert(b.n == b.m);
		matrix res(b.n, b.m);
		matrix::writeIdent(res);
		while(e > 0) {
			if(e & 1LL) res.cpy(matrix::mul(res, b, raux));
			e >>= 1;
			b.cpy(matrix::mul(b, b, raux));
		}
		return res;
	}


	void cpy(const matrix &b) {
		this->n = b.n; this->m = b.m;
		FOR(i,0,b.n) FOR(j,0,b.m) this->mat[i][j] = b.mat[i][j];
	}	

	void print() {
		const char s1[] = "%lld ", s2[] = "%d ";
		const char *s = is_same<T, ll>::value ? s1 : s2;
		FOR(i,0,this->n) { 
			FOR(j,0,this->m) 
				printf(s, this->mat[i][j]);
			printf("\n");
		}
		printf("\n");
	}
};

int main () {

	return 0;

}



