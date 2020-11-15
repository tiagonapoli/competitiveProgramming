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
#define N 100100

// Solves https://codeforces.com/gym/102787/problem/A
mt19937 rnd(time(NULL));

struct Treap {
	int data, priority;
	int sz;
	array<Treap*, 2> kids;
	Treap(int d);
};

inline int size(Treap* t) {
	return t == NULL ? 0 : t->sz;
}

inline void recalc(Treap *t) {
	if(t == NULL) return;
	t->sz = 1;
	for(auto f : t->kids) if(f != NULL) t->sz += f->sz;
}

Treap::Treap(int d) : data(d) {
	kids = {NULL,NULL};
	priority = rnd();
	recalc(this);
}

array<Treap*, 2> split(Treap* t, int nInLeft) {
	if(t == NULL) return {NULL,NULL};

	if(size(t->kids[0]) >= nInLeft) {
		auto lRes = split(t->kids[0], nInLeft);
		t->kids[0] = lRes[1];
		recalc(t);
		return {lRes[0], t};
	} else {
		auto rRes = split(t->kids[1], nInLeft - size(t->kids[0]) - 1);
		t->kids[1] = rRes[0];
		recalc(t);
		return {t, rRes[1]};
	}
}

Treap* merge(Treap* l, Treap* r) {
	if(l == NULL) return r;
	if(r == NULL) return l;
	
	if(l->priority < r->priority) {
		l->kids[1] = merge(l->kids[1], r);
		recalc(l);
		return l;
	} else {
		r->kids[0] = merge(l, r->kids[0]);
		recalc(r);
		return r;
	}
}

inline array<Treap*, 3> splitRange(Treap* t, int a, int b) {
	auto s1 = split(t, b);
	auto s2 = split(s1[0], a-1);
	return {s2[0], s2[1], s1[1]};
}

void print(Treap* t) {
	if(t == NULL) return;
	printf("[%d][%d] [%d]: ", t->sz, t->priority, t->data);
	for(auto el : t->kids) {
		if(el == NULL) {
			printf("NULL ");
			continue;
		}

		printf("[%d][%d][%d] ", el->sz, el->priority, el->data); 
	}

	sep();
	print(t->kids[0]);
	print(t->kids[1]);
}

void printPreOrder(Treap* t) {
	if(t == NULL) return;
	printPreOrder(t->kids[0]);
	printf("%d ", t->data);
	printPreOrder(t->kids[1]);
}

int main () {

	int n = nxt();
	
	Treap* t = NULL;
	For(i,1,n+1) {
		t = merge(t, new Treap(i));
	}

	int a,b;
	For(i,0,n) {
		a = nxt();
		b = nxt();
		if(b <= a) continue;
		int sz = min(b-a, n-b+1);
		auto s1 = splitRange(t, b, b+sz-1);
		auto s2 = splitRange(s1[0], a, a+sz-1);
		t = merge(s2[0], merge(s1[1], merge(s2[2], merge(s2[1], s1[2]))));
	}

	printPreOrder(t);
	sep();

	return 0;
}