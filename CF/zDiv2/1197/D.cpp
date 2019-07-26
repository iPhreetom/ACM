// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define ls (p<<1)
#define rs ((p<<1)+1)
#define mid ((l+r)>>1)
const int maxn = 3e5+7;
int a[maxn];
int ql,qr,x;

struct node{
    int mn,add;
}tree[maxn*4];

inline void pushdown(int p) {
    tree[ls].mn += tree[p].add;
    tree[rs].mn += tree[p].add;
    tree[ls].add += tree[p].add;
    tree[rs].add += tree[p].add;
    tree[p].add = 0;
}

inline void pushup(int p) {
    tree[p].mn = min(tree[ls].mn,tree[rs].mn);
}

void build(int p,int l,int r) {
    if (l == r) {
        tree[p].mn = a[r];
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}

void update(int p,int l, int r) {
    if (ql <= l && r <= qr) {
        tree[p].mn += x;
		tree[p].add += x;
		return ;
    }
    if (tree[p].add != 0) pushdown(p);
    if (ql <= mid) update(ls,l,mid);
    if (qr >= mid+1) update(rs,mid+1,r);
    pushup(p);
}

int query(int p, int l, int r) {
    if (ql <= l && r <= qr) {
        return tree[p].mn;
    }
    if (tree[p].add) pushdown(p);
    int num = 2e18;
    if (ql <= mid) num = min(num, query(ls, l, mid));
    if (qr >= mid+1) num = min(num, query(rs, mid+1, r));
    return num;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}

	int ans = 0;
	x = k;
	for (int j=1; j<=m; j++){
		memset(tree,0,sizeof(tree));
		build(1,1,n);
		// pre add
		if(j != 1) {
			ql = 1; qr = j-1;
			update(1,1,n);
		}

		for (int i=j; i<=n; i+=m){
			if (i != j) {
				ql = 1; qr = i-1;
				update(1,1,n);
				ans = max(ans,a[i]-query(1,1,n));
				ans = max(ans,a[i]-((i+m-1)/m)*k);
			}
			else {
				if (j == 1) ans = max(ans,a[1]-k);
				else {
					ql = 1;
					qr = j-1;
					ans = max(ans,a[i]-query(1,1,n));
					ans = max(ans,a[i]-((i+m-1)/m)*k);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
