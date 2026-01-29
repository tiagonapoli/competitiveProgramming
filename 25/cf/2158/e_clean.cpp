#include "bits/stdc++.h"
using namespace std;

#define N 401000
#define INF 2000000007

int parent[N], minAdj[N];
bool hasHole[N];
int n, m, totalHoles, nodeCount;
int val[N], nodeAt[N]; // linearized grid

int idx(int i, int j) { return i * (m + 2) + j; }

int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (hasHole[a] && hasHole[b]) totalHoles--;
    parent[a] = b;
    hasHole[b] |= hasHole[a];
    minAdj[b] = min(minAdj[a], minAdj[b]);
}

void removeHole(int x) {
    x = find(x);
    if (hasHole[x]) { hasHole[x] = false; totalHoles--; }
}

int dx[] = {-(int)(m + 2), -1, 1, (int)(m + 2)};

void handleQuery(int p, int newVal) {
    // Remove hole from current component (now covered by smaller value)
    removeHole(nodeAt[p]);
    
    int smallestAdj = INF;
    // Update adjacent components and find smallest neighbor
    for (int d = 0; d < 4; d++) {
        int np = p + dx[d];
        smallestAdj = min(smallestAdj, val[np]);
        int comp = find(nodeAt[np]);
        minAdj[comp] = min(minAdj[comp], newVal);
        if (newVal < val[np]) removeHole(comp);
    }
    
    // Create new node
    int node = nodeCount++;
    parent[node] = node;
    hasHole[node] = (smallestAdj > newVal);
    if (hasHole[node]) totalHoles++;
    minAdj[node] = smallestAdj;
    nodeAt[p] = node;
    val[p] = newVal;
    
    // Merge with equal-valued neighbors
    for (int d = 0; d < 4; d++) {
        int np = p + dx[d];
        if (val[np] == newVal) unite(node, nodeAt[np]);
    }
}

int main() {
    int t; scanf("%d", &t);
    
    while (t--) {
        scanf("%d%d", &n, &m);
        
        // Reset dx with correct m
        dx[0] = -(m + 2); dx[3] = (m + 2);
        
        // Initialize border with INF, all pointing to node 0
        nodeCount = 0;
        parent[nodeCount] = nodeCount;
        hasHole[nodeCount] = false;
        minAdj[nodeCount] = INF;
        nodeCount++;
        
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                val[idx(i, j)] = INF;
                nodeAt[idx(i, j)] = 0;
            }
        }
        
        // Initialize grid: all cells start as one component (node 1) with INF value
        parent[nodeCount] = nodeCount;
        hasHole[nodeCount] = true;
        minAdj[nodeCount] = INF;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                nodeAt[idx(i, j)] = 1;
            }
        }
        nodeCount++;
        
        totalHoles = 1;
        
        // Read initial grid values as queries
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x; scanf("%d", &x);
                handleQuery(idx(i, j), x);
            }
        }
        
        printf("%d\n", totalHoles);
        
        int q; scanf("%d", &q);
        while (q--) {
            int r, c, x; scanf("%d%d%d", &r, &c, &x);
            int p = idx(r, c);
            handleQuery(p, val[p] - x);
            printf("%d\n", totalHoles);
        }
    }
    
    return 0;
}
