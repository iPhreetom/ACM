#include<bits/stdc++.h>
using namespace std;

#define ls (p<<1)
#define rs ((p<<1)+1)
#define mid ((l+r)>>1)
const int maxn = 1e5+7;
int a[maxn];
struct node{
    int mx, mn;
    int sum, add;
}tree[maxn*4];

inline void pushdown(int p) {
    if (tree[p].add != 0) {
        tree[ls].mx += tree[p].add;
        tree[ls].add += tree[p].add;
        tree[rs].mx += tree[p].add;
        tree[rs].add += tree[p].add;
        tree[p].add = 0;
    }
}

inline void pushup(int p) {
    tree[p].sum = tree[ls].sum + tree[rs].sum;
    tree[p].mx = max(tree[ls].mx, tree[rs].mx);
    tree[p].mn = min(tree[ls].mn, tree[rs].mn);
}

void build(int p, int l, int r) {
    if (l == r) {
        tree[p].mn = a[r];
        return ;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}

void update(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        tree[p].mx++;
        if (tree[p].mx < tree[p].mn) {
            tree[p].add++;
            return;
        }
        else if (l == r) { // 应该修改
            tree[p].sum++;
            tree[p].mn += a[r];
            return ;
        }
    }
    pushdown(p);
    if (ql <= mid) update(ls,l,mid,ql,qr);
    if (qr >= mid+1) update(rs,mid+1,r,ql,qr);
    pushup(p);
}

int query(int p, int l, int r,int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[p].sum;
    }
    int num = 0;
    pushdown(p);
    if (ql <= mid) num += query(ls,l,mid,ql,qr);
    if (qr >= mid+1) num += query(rs,mid+1,r,ql,qr);
    return num;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    while(cin >> n >> q) {
        memset(tree,0,sizeof(tree));
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        build(1,1,n);
        while(q--){
            string s;
            int x,y;
            cin >> s >> x >> y;
            if (s == "add") {
                update(1,1,n,x,y);
            }
            else {
                cout << query(1,1,n,x,y) << '\n';
            }
        }
    }
}