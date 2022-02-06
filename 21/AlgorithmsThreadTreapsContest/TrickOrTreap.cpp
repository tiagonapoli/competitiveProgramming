#include "bits/stdc++.h"
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

#ifdef DEBUG
	const bool debug = 1;
#else
	const bool debug = 0;
#endif

#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define sepd() if(debug) cout << endl
#define sep() printf("\n");

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
inline int nxt() { int x; scanf("%d", &x); return x; }
#define N 500100

// Solves https://codeforces.com/gym/102787/problem/Z
mt19937 rnd(time(NULL));

struct Treap {
	int priority, sz;
    ll el;
    ll sum;
	array<Treap*, 2> kids;
    Treap* parent;
	Treap(ll el);
};

inline int size(Treap* t) {
	return t == NULL ? 0 : t->sz;
}

inline void recalc(Treap *t) {
	if(t == NULL) return;
	t->sz = 1;
    t->sum = t->el;
	for(auto f : t->kids) if(f != NULL) {
        t->sz += f->sz;
        t->sum += f->sum;
    }
}

inline void updateParent(Treap *t, Treap *par) {
    if(t == NULL) return;
    t->parent = par;
}

inline Treap* findRoot(Treap *t) {
    while(t->parent != NULL) {
        t = t->parent;
    }

    return t;
}

Treap::Treap(ll el) : el(el) {
	kids = {NULL,NULL};
    parent = NULL;
	priority = rnd();
	recalc(this);
}

array<Treap*, 2> split(Treap* t, int nInLeft) {
	if(t == NULL) return {NULL,NULL};

	if(size(t->kids[0]) >= nInLeft) {
        updateParent(t->kids[0], NULL);
		auto lRes = split(t->kids[0], nInLeft);
		t->kids[0] = lRes[1];
        updateParent(t->kids[0], t);
		recalc(t);
		return {lRes[0], t};
	} else {
        updateParent(t->kids[1], NULL);
		auto rRes = split(t->kids[1], nInLeft - size(t->kids[0]) - 1);
		t->kids[1] = rRes[0];
        updateParent(t->kids[1], t);
		recalc(t);
		return {t, rRes[1]};
	}
}

Treap* merge(Treap* l, Treap* r) {
	if(l == NULL) return r;
	if(r == NULL) return l;
	
	if(l->priority < r->priority) {
        updateParent(l->kids[1], NULL);
		l->kids[1] = merge(l->kids[1], r);
        updateParent(l->kids[1], l);
		recalc(l);
		return l;
	} else {
        updateParent(r->kids[0], NULL);
		r->kids[0] = merge(l, r->kids[0]);
        updateParent(r->kids[0], r);
		recalc(r);
		return r;
	}
}

inline array<Treap*, 3> splitRange(Treap* t, int a, int b) {
	auto s1 = split(t, b);
	auto s2 = split(s1[0], a-1);
	return {s2[0], s2[1], s1[1]};
}

int main () {

    Treap* t[N];
	int n = nxt();
    int y,z;

    For(i,0,n) {
        int a = nxt();

        if(a == 1) {
            t[i+1] = new Treap(nxt()); 
        } else if(a == 2) {
            y = nxt(), z = nxt();
            auto r1 = findRoot(t[y]);
            auto r2 = findRoot(t[z]);
            if(r1 == r2) continue;
            merge(r1, r2);
        } else if(a == 3) {
            y = nxt(), z = nxt();
            auto r = findRoot(t[y]);
            if(r->sz <= z) continue;
            split(r, z);
        } else {
            y = nxt(); 
            auto r = findRoot(t[y]);
            printf("%lld\n", r->sum);
        }
    }

	return 0;
}