// 支持第k大的BIT
// 下标从1开始
struct Tbit {
    int size;
    ll t[MAXN];

    int lowbit(int x) { return x & (-x); }

    void init(int sz) {
        size = sz + 1;
        memset(t, 0, (sz + 2) * sizeof(ll));
    }

    void add(int p, ll x) {
        if (p <= 0) return;
        for (; p <= size; p += lowbit(p)) t[p] += x;
    }

    ll get(int p) {
        ll sum = 0;
        for (; p > 0; p -= lowbit(p)) sum += t[p];
        return sum;
    }

    void update(int p, ll x) { add(p, x - query(p, p)); }
    ll query(int l, int r) { return get(r) - get(l - 1); }

    int kth(ll k) {
        int p = 0;
        for (int i = 20; i >= 0; i--) {
            int p_ = p + (1 << i);
            if (p_ <= size && t[p_] < k) {
                k -= t[p_];
                p = p_;
            }
        }
        return p + 1;
    }
};