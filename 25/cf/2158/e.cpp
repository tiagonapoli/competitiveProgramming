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
#define N 101100

// #define INF 19
#define INF 2000000000

// We do some kind of DSU structure to keep track of all connected components with same number
// Every time a number gets decreased, it will either enter an existing connected parent, if
// it has now the same number, or it will create a new one.
// Number of components is limited by N*M + Q <= 2*10**5

// When we reduce a number, we need to:
// - If the new number is equal to some other adjacent number, enter the parent there - Otherwise, create a new parent.
// - Remove the hole, if existing, from all adjacent compnents that are greater than the new number
// - If the new number is strictly less than all of the adjacent numbers, add a new hole there

struct Cell {
	int nodeId;
	ll value;
};

vector<int> parent;
vector<bool> hasHole;
vector<ll> adjMin;
vector<vector<Cell>> grid;
int totalHoles;
int n, m;

int find(int x) {
	if(parent[x] == x) {
		return x;
	}

	return parent[x] = find(parent[x]);
}


void join(int a, int b) {
	// When we join two components we need to join the adjMin and ensure only one hole exists
	// after the merger
	a = find(a);
	b = find(b);
	if (a == b) return;

	parent[a] = b;
	adjMin[b] = min(adjMin[a], adjMin[b]);
	adjMin[a] = INF;
	if (hasHole[a] && hasHole[b]) {
		totalHoles--;
	}

	bool hadHoleA = hasHole[a];
	hasHole[a] = false;
	hasHole[b] = hasHole[b] | hadHoleA;
}

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

Cell getCellAtPos(int x, int y, int dir) {
	int xx = x + dx[dir];
	int yy = y + dy[dir];
	return grid[xx][yy];
}

void ensureHoleInComponent(int comp) {
	comp = find(comp);
	if (!hasHole[comp]) {
		hasHole[comp] = true;
		totalHoles++;
	}
}

void removeHoleInComponent(int comp) {
	comp = find(comp);
	if (hasHole[comp]) {
		hasHole[comp] = false;
		totalHoles--;
	}
}

void updateComponentAffectedByNewValue(int x, int y, int dir, ll newValue) {
	Cell cell = getCellAtPos(x, y, dir);
	int comp = find(cell.nodeId);
	adjMin[comp] = min(adjMin[comp], newValue);
	if (newValue < cell.value) {
		// If the new value is less than this cell's current value, this component is doomed
		// it will never have a hole again - the current nodes will never have a hole
		removeHoleInComponent(comp);
	}

}

void handleQuery(int x, int y, int reduce) {
	ll newValue = grid[x][y].value - reduce;

	// We remove the hole from the current parent:
	// - We are reducing a member from the current copmnent, which means the current parent will now be covered
	// by this new member, if not covered yet by anyone else
	// - Even if we divide the current parent into two, like in the nodeId example:
	// 2 2 2 1 2 2 2
	// The nodes with 2 won't ever have a hole as 2 anymore. They will have to be reduced to have a hole, so
	// it doesn't matter if according to the union-find they are in the same parent - They won't be touched
	// anymore - We don't care about them anymore since they can't ever have a hole again, unless new nodes are
	// created by reducing elements.
	removeHoleInComponent(find(grid[x][y].nodeId));

	// When reducing a spot, we need to first remove the holes from the components
	// adjacent from this current spot, if a hole exist there, in case the new value
	// is smaller
	ll smallestAdjacent = INF;
	for (int i=0;i<4;i++) {
		smallestAdjacent = min(getCellAtPos(x, y, i).value, smallestAdjacent);
		updateComponentAffectedByNewValue(x, y, i, newValue);
	}

	// Create a new parent for the new value
	// It will only have a hole if it's the smallest element of all adjacent ones
	parent.pb(0);
	int nodeId = (int)parent.size() - 1;
	parent[nodeId] = nodeId;
	adjMin[nodeId] = smallestAdjacent;
	hasHole[nodeId] = 0;
	if (smallestAdjacent > newValue) {
		ensureHoleInComponent(nodeId);
	}
	grid[x][y] = { nodeId, newValue };
	

	// Now we need to check if this current parent should be merged with any other
	// adjacent components, in case it's equal to them.
	for (int i=0;i<4;i++) {
		if (getCellAtPos(x, y, i).value == newValue) {
			// if both components have a hole, 'join' will reduce totalHoles accordingly
			join(nodeId, getCellAtPos(x, y, i).nodeId);
		}
	}

	// Now we check if any of the adjancent components, with the adjMin updated,
	// should have their holes removed.
	for (int i=0;i<4;i++) {
		Cell cell = getCellAtPos(x, y, i);
		int comp = find(cell.nodeId);
		if (adjMin[comp] < cell.value) {
			removeHoleInComponent(comp);
		}
	}
}

void printGridForDebugging() {
	if (!debug) return;

	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			Cell cell = grid[i][j];
			if (find(cell.nodeId) != cell.nodeId) {
				printf("%2lld[%2d][_][__] ", cell.value, cell.nodeId);
				continue;
			}

			bool hole = hasHole[cell.nodeId];
			printf("%2lld[%2d][%1d][%2lld] ", cell.value, cell.nodeId, hole, adjMin[cell.nodeId]);
		}
		sep();
	}
}

int main () {

	int t = nxt();

	parent.reserve(4 * N);
	hasHole.reserve(4 * N);
	adjMin.reserve(4 * N);

	while(t--) {
		n = nxt();
		m = nxt();

		parent.clear();
		hasHole.clear();
		adjMin.clear();
		
		grid.resize(n+2);
		parent.pb(0);
		hasHole.pb(0);
		adjMin.pb(INF);
		for (int i=0;i<=n+1;i++) {
			grid[i].resize(m+2);
			for(int j=0;j<=m+1;j++) {
				grid[i][j].value = INF;
				grid[i][j].nodeId = 0;
			}
		}

		// Initially the entire grid is in the same connected component
		// Everyone has NodeId 1 for simplicity
		parent.pb(1);
		hasHole.pb(1);
		adjMin.pb(INF);
		for (int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				grid[i][j].nodeId = 1;
			}
		}

		printGridForDebugging();

		totalHoles = 1;
		for (int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				int target = nxt();
				handleQuery(i, j, INF - target);
				printGridForDebugging();
			}
		}

		printf("%d\n", totalHoles);

		int q = nxt();
		int a,b,x;
		for (int i=0;i<q;i++) {
			a = nxt();
			b = nxt();
			x = nxt();
			handleQuery(a, b, x);
			printf("%d\n", totalHoles);
			printGridForDebugging();
		}
	}


	return 0;

}

