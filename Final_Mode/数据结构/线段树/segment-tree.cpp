#define ls (p<<1)
#define rs ((p<<1)+1)
#define mid ((l+r)>>1)
const int maxn = 1e5+7;
int a[maxn];
int ql,qr;

struct node{
    int mn,sum,add;
}tree[maxn*4];

inline void pushdown(int p) {
    tree[ls].mn += tree[p].add;
    tree[rs].mn += tree[p].add;
    tree[ls].add += tree[p].add;
    tree[rs].add += tree[p].add;
    tree[p].add = 0;
}

inline void pushup(int p) {
    tree[p].sum = tree[ls].sum + tree[rs].sum;
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
        tree[p].mn -= 1;
        if (tree[p].mn > 0) {
            tree[p].add -= 1;
            return;
        }
        else if (l == r) { // == 0
            tree[p].mn = a[r];
            tree[p].sum++;
            return ;
        }
    }
    if (tree[p].add != 0) pushdown(p);
    if (ql <= mid) update(ls,l,mid);
    if (qr >= mid+1) update(rs,mid+1,r);
    pushup(p);
}

int query(int p, int l, int r) {
    if (ql <= l && r <= qr) {
        return tree[p].sum;
    }
    if (tree[p].add) pushdown(p);
    int num = 0;
    if (ql <= mid) num += query(ls, l, mid);
    if (qr >= mid+1) num += query(rs, mid+1, r);
    return num;
}
