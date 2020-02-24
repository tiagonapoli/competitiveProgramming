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
#define N 200100
#define MAXLOG 30

int logg[N];
inline void precalcLogs() {
	logg[1] = 0;
    for(int i=2;i<N;i++) {
        logg[i] = logg[i/2] + 1;
    }
}

vector<int> treeAdj[N];
int treeH[N];
int treeFather[N][MAXLOG];

struct Tree {

    static int used;

    // comment checkNode and checkForest for performance
    // maybe change dynamic allocation to compile time?

    int n, minN, maxN;
    int firstVertex;
    bool checkedForForest;

    Tree(int n, int firstVertex) {
        this->n = n;
        this->minN = Tree::used;
        this->maxN = Tree::used+n;
        Tree::used += n;

        this->firstVertex = firstVertex;
        this->checkedForForest = false;

        for(int i=this->minN;i<this->maxN;i++) {
            treeH[i] = -1;
            treeAdj[i].clear();
            for(int j=0;j<30;j++) {
                treeFather[i][j] = -1;
            }
        }
    }

    inline int mapVertex(const int u) {
        return u - this->firstVertex + this->minN;
    }

    inline int invMapVertex(const int u) {
        return u - this->minN + this->firstVertex;
    }

    inline void checkNode(const int u) {
        assert(u >= this->minN && u < this->maxN);
    }

    inline void checkForest() {
        this->checkedForForest = true;
        for(int i=this->minN;i<this->maxN;i++) {
           assert(treeFather[i][0] != -1);
        }
    }

    void addEdge(int a, int b) {
        a = mapVertex(a);
        b = mapVertex(b);
        this->checkNode(a);
        this->checkNode(b);
        treeAdj[a].pb(b);
        treeAdj[b].pb(a);
    }

    void readTreeByFather(int treeRoot) {
        treeRoot = mapVertex(treeRoot);
        int a;
        for(int i=this->minN; i<this->maxN; i++) {
            if(i == treeRoot) continue;
            scanf("%d", &a);
            this->checkNode(a);
            this->addEdge(i,a);
        }
    }

	inline void prepareLca(int treeRoot) {
        treeRoot = mapVertex(treeRoot);
        precalcLogs();
        treeFather[treeRoot][0] = treeRoot;
        treeH[treeRoot] = 0;
        this->dfsLcaSetup(treeRoot);
        calcSparseTable();
	}

    inline void calcSparseTable() {
        for(int i=this->minN;i<this->maxN; i++) {
            for(int j=1;j<MAXLOG;j++) {
                treeFather[i][j] = treeFather[treeFather[i][j-1]][j-1];
            }
        }
    }

    void dfsLcaSetup(const int u) {
        this->checkNode(u);
        for(int v : treeAdj[u]) {
            this->checkNode(v);
            if(v != treeFather[u][0]) {
                treeFather[v][0] = u;
                treeH[v] = treeH[u] + 1;
                this->dfsLcaSetup(v);
            }
        }
    }

	inline int goUp(int node, int cnt) {
		this->checkNode(node);
		int j=0;
		while(cnt > 0) {
			if(cnt & 1) {
				node = treeFather[node][j];
			}
			cnt >>= 1;
			j++;
		}
		return node;
	}

    inline int lca(int u, int v) {
        if(this->checkedForForest == false) {
            this->checkForest();
        }

        u = mapVertex(u);
        v = mapVertex(v);


        this->checkNode(u);
        this->checkNode(v);
        //u esta mais embaixo
        if(treeH[u] < treeH[v]) swap(u,v);
        u = this->goUp(u, treeH[u] - treeH[v]);
        if(u == v) return invMapVertex(v);
        for(int i=19;i >= 0; i--) {
            if(treeFather[u][i] != treeFather[v][i]) {
                u = treeFather[u][i];
                v = treeFather[v][i];
            }
        }
        return invMapVertex(treeFather[u][0]);
    }

    void printAdj() {
        for(int i=this->minN; i<this->maxN; i++) {
            printf("%d h=%d: ", i, treeH[i]);
            for(int j : treeAdj[i]) {
                printf("%d ", j);
            }
            printf("\n");
        }
        printf("\n");
    }

    void free() {
        Tree::used = 0;
    }
};

int Tree::used = 0;

int main () {


    return 0;
}



