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

struct edge {
	string to;
	pii op;
};

map<string, vector<edge>> adj;
map<string, map<string, vector<pii>>> dist;

bool isPalindrome(string_view s) {
	if(s.size() <= 1) return false;
	for (int i=0;i < s.size() - i - 1; i++) {
		if (s[i] != s[s.size() - i - 1]) return false;
	}

	return true;
}

string getReverse(const string& str, int ini, int sz) {
	string ret = str;
	while(sz-- > 0) {
		ret[ini] = ret[ini] == '0' ? '1' : '0';
		ini++;
	}

	return ret;
}

void addAdj(const string& str) {
	string_view now(str);
	for (int i=0;i<now.size(); i++) {
		for (int sz = 2; i + sz - 1 < now.size(); sz++) {
			if (isPalindrome(now.substr(i, sz))) {
				adj[str].pb({ getReverse(str, i, sz), { i, i+sz - 1 } });
			}
		}
	}
}

void bfs(const string& start) {
	auto& distFromStart = dist[start];
	std::queue<pair<string, vector<pii>>> queue;
	distFromStart[start] = {};
	queue.push({ start, {} });
	while(!queue.empty()) {
		auto now = queue.front();
		queue.pop();
		for (auto& nxt : adj[now.fi]) {
			if (distFromStart.contains(nxt.to)) {
				continue;
			}
			vector<pii> ops = now.se;
			ops.pb(nxt.op);
			distFromStart[nxt.to] = ops;
			queue.push({ nxt.to, std::move(ops) });
		}
	}
}

void init() {
	for(int i=0;i<16;i++) {
		string val = bitset<4>(i).to_string();
		adj[val] = {};
		addAdj(val);
	}

	for (int i=0;i<16;i++) {
		string val = bitset<4>(i).to_string();
		bfs(val);
	}

	if (debug) {
		for(auto& kv : adj) {
			printf("[%s]: ", kv.fi.c_str());
			for (auto edge : kv.se) {
				printf("[%s][%d,%d] ", edge.to.c_str(), edge.op.fi, edge.op.se);
			}
			sep();
		}

		for (auto& kv : dist) {
			for(auto& d : kv.se) {
				printf("dist [%s -> %s]: %d - ", kv.fi.c_str(), d.fi.c_str(), (int)d.se.size());
				for (auto& p : d.se) {
					printf("[%d,%d] ", p.fi, p.se);
				};
				sepd();
			}
			sepd();
		}
	}
}

char negateDigit(char c) {
	return c == '0' ? '1' : '0';
}

void get3DigitTransitionAndTransform(span<char> cur, int offset, vector<pii>& res) {
	string_view str(cur.data(), cur.size());
	if (str == "000" || str == "010" || str == "101" || str == "111") {
		cur[0] = negateDigit(cur[0]);
		cur[1] = negateDigit(cur[1]);
		cur[2] = negateDigit(cur[2]);
		res.pb({ offset, offset+2 });
		return;
	}
	
	if (str == "001" || str == "110") {
		cur[0] = negateDigit(cur[0]);
		cur[1] = negateDigit(cur[1]);
		res.pb({ offset, offset+1 });
		return;
	}

	// (str == "011" || str == "100") {
	cur[1] = negateDigit(cur[1]);
	cur[2] = negateDigit(cur[2]);
	res.pb({ offset+1, offset+2 });
	// now it became 000 / 111 - we can call get3DigitTransitionAndTransform again to handle that
	get3DigitTransitionAndTransform(cur, offset, res);
}

int main () {

	init();

	vector<pii> res;
	res.reserve(10'000);
	int t = nxt();
	while(t--) {
		int n = nxt();
		string source, dest;
		cin >> source >> dest;

		// Until the last 4 elements, we just look at the first digit at each step and do a best effort to
		// just transform that first digit in 0 / 1, as required
		// We only look at 3 digits at this point, which only has 8 transitions
		span<char> str(source.data(), source.size());
		span<char> cur;
		for (int i=0;i+3<n;i++) {
			if (str[i] == dest[i]) {
				continue;
			}

			cur = str.subspan(i, 3);
			get3DigitTransitionAndTransform(cur, i, res);
		}

		// Now we're at the last 4 digits - We need to get the distance between cur and target
		for (pii op : dist[source.substr(n-4,4)][dest.substr(n-4, 4)]) {
			op.fi += n - 4;
			op.se += n - 4;
			res.pb(op);
		}

		printf("%d\n", res.size());
		for(pii op : res) {
			printf("%d %d\n", op.fi+1, op.se+1);
		}

		printf("\n");
		res.clear();
	}

	return 0;

}

