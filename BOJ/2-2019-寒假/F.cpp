// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];
int b[maxn];

struct node {
	pair<int,int> lazy;
	int t;
	int l, r;
	#define l(p)  tree[p].l
	#define r(p)  tree[p].r
	#define lazy(p)  tree[p].lazy
	#define t(p)  tree[p].t
}tree[maxn * 4];

void build(int p, int l, int r) {
	l(p) = l;
	r(p) = r;
	if(l == r) {
		lazy(p) = make_pair(0,0);
		t(p) = 0;
		return ;
	}

	int mid = (r+l)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
}

void spread(int p) {
	if(lazy(p).first != 0) {
		if(t(p*2) < t(p)) lazy(p*2) = lazy(p), t(p*2) = t(p);
		if(t(p*2+1) < t(p)) lazy(p*2+1) = lazy(p), t(p*2+1) = t(p);
		lazy(p) = make_pair(0,0);
		t(p) = 0;
	}
}

void change(int p, int l, int r, int as, int bs, int cnt) {
	if(l <= l(p) && r(p) <= r) {
		lazy(p) = make_pair(as,bs);
		t(p) = cnt;
		return ;
	}

	spread(p);
	int mid = (r(p)+l(p))/2;
	if(l <= mid) change(p*2, l, r, as, bs, cnt);
	if(r > mid) change(p*2+1, l, r, as, bs, cnt);
}

int ask(int p,int l, int r) {
	if(l <= l(p) && r(p) <= r) {
		int as = lazy(p).first;
		int bs = lazy(p).second;
		if(bs == 0) {
			return b[l];
		}
		assert(l >= bs);
		return a[as + (l - bs)];
	}

	spread(p);
	int mid = (l(p)+r(p))/2;
	int ret = 0;
	if(l <= mid) ret = ask(p*2, l, r);
	if(r > mid) ret = ask(p*2+1, l, r);
	return ret;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	for (int i=1; i<=n; i++){
		cin>>b[i];
	}

	build(1, 1, n);
	int cnt = 0;
	while(m--) {
		cnt++;
		int t;
		cin >> t;
		if(t == 1) {
			int x, y, k;
			cin >> x >> y >> k;
			change(1, y, y+k-1, x, y, cnt);
		}
		else {
			int p;
			cin >> p;
			cout << ask(1, p, p) <<endl;
		}
	}

	return 0;
}
