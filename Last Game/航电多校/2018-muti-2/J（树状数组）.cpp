#include<bits/stdc++.h>
using namespace std;

// 支持第k大的BIT
// 下标从1开始
int size;
int t[2012345];

int lowbit(int x) { return x & (-x); }

void init(int sz) {
    size = sz + 1;
    memset(t, 0, (sz + 2) * sizeof(int));
}

void add(int p, int x) {
    if (p <= 0) return;
    for (; p <= size; p += lowbit(p)) t[p] += x;
}

int get(int p) {
    int sum = 0;
    for (; p > 0; p -= lowbit(p)) sum += t[p];
    return sum;
}

int main () {
    ios::sync_with_stdio(0);cin.tie(0);
    int n,x,y;
    while(cin >> n >> x >> y) {
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }

        vector<int> a(v);
        long long ans = 0;
        map<int,int> mp;
        
        // sort(a.begin(),a.end());
        // int lse = a.size();
        // a.erase(unique(a.begin(),a.end()),a.end());
        // assert(true);
        
        for (int i=0; i<a.size(); i++) {
            mp[a[i]] = i+2;
        }
        int cnt = 0;
        for (auto &i:mp) {
            i.second = ++cnt;
        }

        init(n+3);
        for (int i=n-1; i>=0; i--) {
            int val = mp[v[i]]+1;
            ans += get(val-1);
            add(val,1);
        }
        ans *= min(x,y);

        cout << ans << '\n';
    }
}