// 一句话题解
	// 树状数组求解逆序对个数
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;

// 支持第k大的BIT
// 下标从1开始
const int MAXN = 512345;
typedef long long ll;
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
}bit;

signed main(){
	int n;
	while(scanf("%d",&n)!=EOF) {
		if (n==0) break;
		bit.init(n+1);
		ll ans = 0;
		vector<int> v;
		vector<int> order;
		for (int i=0; i<n; i++){
			int tp;
			scanf("%d",&tp);
			v.push_back(tp);
		}
		order = v;
		sort(order.begin(),order.end());
		for (int i=0; i<v.size(); i++){
			v[i] = lower_bound(order.begin(),order.end(),v[i])-order.begin()+1;
		}
		for (int i=v.size()-1; i>=0; i--) {
			ans += bit.query(0,v[i]);
			bit.update(v[i],1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
