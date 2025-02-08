#include "bits/stdc++.h"
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define ull unsigned long long

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
mt19937 rnd(1);

const ull M1 = 1000000007;
const ull P = 31;
ull pow1[N], pow2[N];

struct StringHash {
	int sz;
	ull hash1;
	ull hash2;

	StringHash(){
		sz = hash1 = hash2 = 0;
	}

	StringHash(char c) {
		sz = 1;
		hash1 = hash2 = (c - 'a');
	}

	bool operator== (const StringHash &b) const {
		return this->sz == b.sz && this->hash1 == b.hash1 && this->hash2 == b.hash2; 
	}
};

StringHash concatenateHashes(StringHash a, StringHash b) {
	StringHash ret;
	ret.hash1 = (a.hash1 + pow1[a.sz] * b.hash1) % M1;
	ret.hash2 = a.hash2 + pow2[a.sz] * b.hash2;
	ret.sz = a.sz + b.sz;
	return ret;
}

struct Treap {
	char c;
	StringHash hash;
	int priority;
	int sz;
	array<Treap*, 2> kids;
	Treap(char c);
};

inline int size(Treap* t) {
	return t == NULL ? 0 : t->sz;
}

inline StringHash getHash(Treap *t) {
	return t == NULL ? StringHash() : t->hash;
}

inline void recalc(Treap *t) {
	if(t == NULL) return;
	t->sz = 1;
	for(auto f : t->kids) if(f != NULL) t->sz += f->sz;
	t->hash = concatenateHashes(getHash(t->kids[0]), concatenateHashes(StringHash(t->c), getHash(t->kids[1])));
}

Treap::Treap(char ch) : c(ch) {
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
	prin(a);
	prin(b);
	auto s1 = split(t, b);
	auto s2 = split(s1[0], a-1);
	return {s2[0], s2[1], s1[1]};
}

void print(Treap* t) {
	if(t == NULL) return;
	printf("[%d][%d] [%c %d/%lld/%lld]: ", t->sz, t->priority, t->c, t->hash.sz, t->hash.hash1, t->hash.hash2);
	for(auto el : t->kids) {
		if(el == NULL) {
			printf("NULL ");
			continue;
		}

		printf("[%d][%d] [%c %d/%lld/%lld] ", el->sz, el->priority, el->c, el->hash.sz, el->hash.hash1, el->hash.hash2);
	}

	sep();
	print(t->kids[0]);
	print(t->kids[1]);
}

void printPreOrder(Treap* t) {
	if(t == NULL) return;
	printPreOrder(t->kids[0]);
	printf("%c ", t->c);
	printPreOrder(t->kids[1]);
}

int main () {

	pow1[0] = pow2[0] = 1;
	for(int i=1;i<N;i++) {
		pow1[i] = (pow1[i-1] * P) % M1;
		pow2[i] = pow2[i-1] * P;
	}

	int n = nxt();
	int q = nxt();
	string s;
	cin >> s;

	Treap* t = NULL;
	Treap* tInv = NULL;
	For(i,0,n) {
		t = merge(t, new Treap(s[i]));
		tInv = merge(tInv, new Treap(s[n-i-1]));
	}

	// printPreOrder(t);
	// sepd();
	// printPreOrder(tInv);
	// sepd();
	// sepd();

	For(i,0,q) {
		int a = nxt();
		if(a == 1) {
			int b = nxt(), c = nxt();
			auto r = splitRange(t, b, c);
			t = merge(r[0], r[2]);

			r = splitRange(tInv, size(tInv)-c+1, size(tInv)-b+1);
			tInv = merge(r[0], r[2]);

		} else if(a == 2) {
			char b;
			int p;
			scanf(" %c %d", &b, &p);
			auto r = split(t, p-1);
			t = merge(r[0], new Treap(b));
			t = merge(t, r[1]);

			r = split(tInv, size(tInv)-p+1);
			tInv = merge(r[0], new Treap(b));
			tInv = merge(tInv, r[1]);

		} else {
			int b = nxt(), c = nxt();

			auto r1 = splitRange(t, b, c);
			auto r2 = splitRange(tInv, size(tInv)-c+1, size(tInv)-b+1);
			if(r1[1]->hash == r2[1]->hash) {
				printf("yes\n");
			} else printf("no\n");
			t = merge(r1[0], merge(r1[1], r1[2]));
			tInv = merge(r2[0], merge(r2[1], r2[2]));
		}

		// printPreOrder(t);
		// sepd();
		// printPreOrder(tInv);
		// sepd();
		// sepd();
	}

	return 0;
}