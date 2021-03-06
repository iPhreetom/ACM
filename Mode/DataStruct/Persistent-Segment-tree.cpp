#include<bits/stdc++.h>
using namespace std;

const int MAX_MLOGN = 1e6;
const int MAX_M = 2e5;
const int MAX_N = 2e5;

struct SegmentTree{
	int lc, rc;
	int dat;
} tree[MAX_MLOGN];
int tot, root[MAX_M];
int n, a[MAX_N];

int build(int l,int r){
	int p = ++tot;
	if(l == r){
		tree[p].dat = a[l];
		return p;
	}
	int mid = l+(r-l)/2;
	tree[p].lc = build(l,mid);
	tree[p].rc = build(mid+1,r);
	tree[p].dat = max(tree[tree[p].lc].dat , tree[tree[p].rc].dat);
}

// root[0] = build(1,n);

int insert(int now, int l,int r,int x,int val){
	int p = ++tot;
	tree[p] = tree[now];
	if(l == r){
		tree[p].dat = val;
		return p;
	}
	int mid = (l+r)>>1;
	if(x <= mid){
		tree[p].lc = insert(tree[now].lc, l, mid, x, val);
	}
	else{
		tree[p].rc = insert(tree[now].rc, mid+1, r, x, val);
	}
	tree[p].dat = max(tree[tree[p].lc].dat, tree[tree[p].rc].dat);
	return p;
}

// root[i] = insert(root[i-1], 1, n, x, val);

int ask(int p, int l, int r, int ql,int qr){
	if(l <= ql && r >= qr){
		return tree[p].dat;
	}

	int mid = (l + r)/2;
	int val = 0;

	if(l<=mid)val = max(ask(tree[p].lc, l, mid, ql, qr), val);
	if(r > mid)val = max(ask(tree[p].rc, mid+1, r, ql, qr), val);
	return val;
}
// ask(1, 1, n, l, r);
