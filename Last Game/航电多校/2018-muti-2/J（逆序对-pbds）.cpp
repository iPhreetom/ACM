#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;
template<class T>
using rank_set = tree<T, null_type, std::greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<class Key, class T>
// using rank_map = tree<Key, T, std::less<Key>, rb_tree_tag, tree_order_statistics_node_update>;


signed main () {
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int n,x,y;
    while(cin >> n >> x >> y) {
        rank_set<long long> st;
        long long ans = 0;
        int cnt = 0;
        for (int i=0; i<n; i++) {
            int t;
            cin >> t;
            long long tp = t;
            tp *= 100000000;
            tp -= ++cnt;
            st.insert(tp);
            ans += st.order_of_key(tp);
        }
        ans *= min(x,y);
        cout << ans << '\n';
    }
}