#include "bits/stdc++.h"
#include <sys/time.h>
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

int p[N];
int find(int x) {
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	p[b] = a;
}

int main () {

     struct timeval time; 
     gettimeofday(&time,NULL);

     // microsecond has 1 000 000
     // Assuming you did not need quite that accuracy
     // Also do not assume the system clock has that accuracy.
     srand((time.tv_sec * 1000) + (time.tv_usec / 1000));


	int n = 10;
    for(int i=0;i<=n;i++) p[i] = i;
    int k = 1 + (rand() % n);
	printf("%d %d\n", n, k);

	int cnt = 0;
	while(cnt < n-1) {
		int x = 1 + (rand() % n);
		int y = 1 + (rand() % n);
		if(find(x) != find(y)) {
			join(x,y);
			printf("%d %d\n", x, y);
            cnt++;
		}
	}

	return 0;

}



