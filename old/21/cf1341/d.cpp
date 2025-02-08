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

int nums[10] = {
	0b1110111,
	0b0010010,
	0b1011101,
	0b1011011,
	0b0111010,
	0b1101011,
	0b1101111,
	0b1010010,
	0b1111111,
	0b1111011,
};

int v[N];

inline int dist(int now, int target) {
	if((now & nums[target]) != now) return -1;
	return __builtin_popcount(now ^ nums[target]);
}

bool dp[2010][2010][11];
int n;

void print(int pos, int remaning) {
	if(pos == n) return;
	for(int i=9;i>=0;i--) {
		if(dp[pos][remaning][i] == 1) {
			printf("%d", i);
			return print(pos+1, remaning - dist(v[pos], i));
		}
	}
}

int main () {

	int k;
	n = nxt();
	k = nxt();

	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		bitset<8> aux(s.c_str());
		v[i] = (int) aux.to_ulong();
	}

	for(int x=0;x<10;x++) {
		int d = dist(v[n-1], x);
		if(d == -1) continue;
		dp[n-1][d][x] = 1; 
		dp[n-1][d][10] = 1;
	}


	for(int i=n-2;i>=0;i--) {
		int maxj = min((n-1 - i + 1) * 8, k);
		for(int j=0;j<=k;j++) {
			for(int x=0;x<10;x++) {
				int d = dist(v[i], x);
				if(d > j || d == -1) continue;
				
				if(debug) {
					printf("Distance [%d -> %d] %d\n", v[i], x, d);
					printf("[%d][%d][%d] = [%d][%d][%d] %d\n", i, j, x, i+1, j-d, 10, dp[i+1][j-d][10]);
					sep();
				}

				dp[i][j][x] = dp[i+1][j - d][10];
				dp[i][j][10] |= dp[i][j][x];
			}
		}
	}
	
	if(dp[0][k][10] == 0) {
		printf("-1\n");
		return 0;
	}

	print(0, k);
	printf("\n");

	if(debug)
	for(int i=0;i<n;i++) {
		for(int j=0;j<=k;j++) {
			printf("[%d %d]: ", i, j);
			for(int x=0;x<=10;x++) {
				printf("[%d]%d  ", x, dp[i][j][x]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;

}



