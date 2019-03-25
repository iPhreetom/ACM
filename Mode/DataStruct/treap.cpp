#include<bits/stdc++.h>
using namespace std;

const int maxn = 100000;

struct treap {
	int l,r;
	int cnt;
	int val;
	int size
	int dat;
} a[maxn];

int root;
int tot;
int n;
int inf = 0x7fffffff;

int New(int val) {
	a[++tot].val = val;
	a[tot].dat = rand();
	a[tot].size = a[tot].cnt = 1;
	return tot;
}

void Update(int p){
	a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
}


void Build() {
	tot = 0;
	root = 1;
	New(-inf);
	New(inf);
	a[root].r = 2;
	Update(root);
}

// 查询值是第几大
int GetRank(int p,int val) {
	// defualt p is root
	if(p == 0) return 0;
	if(val == a[p].val) return a[a[p].l].size + 1;
	if(val < a[p].val) return GetRank(a[p].l, val);
	return GetRank(a[p].r, val) + a[a[p].l].size + a[p].cnt;
}

// 查询第k大是谁
int Getval(int p, int rank) {
	if (p == 0) return inf;
	if (a[a[p].l].size >= rank) return GetRank(a[p].l, rank);
	if (a[a[p].l].size + a[p].cnt >= rank) return a[p].val;
	return Getval(a[p].r, rank - a[a[p].l].size - a[p].cnt);
}

void RotateWithLeftSon(int &p) {
	int q = a[p].l;
	a[q].l = a[p].r;
	a[p].r = p;
	p = q;
	Update(a[p].r);
	Update(p);
}

void RotateWithRightSon(int &p) {
	int q = a[p].r;
	a[p].r = a[q].l;
	a[q].l = p;
	p = q;
	Update(a[p].l);// origin-father will be in the origin-son's left son;
	Update(p);
}

void Insert(int &p, int val) {
	if (p == 0) {
		p = New(val);
		return ;
	}

	if (a[p].val == val) {
		a[p].cnt++;
	}
	else if(a[p].val < val) {
		Insert(a[p].r, val);
		if (a[p].dat < a[a[p].r].dat) RotateWithRightSon(p);
	}
	else {
		Insert(a[p].l, val);
		if (a[p].dat < a[a[p].l].dat) RotateWithLeftSon(p);
	}
	Update(p);
}
