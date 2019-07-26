// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxn = 1e6+5;
struct node {
    int p[31], v[31];
} f[maxn];
int a[maxn];

void add(int i, int x) {
    for (int j=0; j<31; j++){
        f[i].p[j] = f[i-1].p[j];
        f[i].v[j] = f[i-1].v[j];
    }
    int k = i;
    for (int j=30; ~j; --j) {
        if ((x>>j)&1) {
            if (f[i].v[j]) {
                if (f[i].p[j] < k) {
                    swap(f[i].p[j],k);
                    swap(f[i].v[j],x); // swap 的时候 i 会变化， 所以位置信息要用一个新的变量维护。
                }
                x ^= f[i].v[j];
            }
            else {
                f[i].v[j] = x;
                f[i].p[j] = k;
                break;
            }
        }
    }
}

int ask(int l,int r) {
    int ret = 0;
    for (int j=30; ~j; --j) {
        if ((ret^f[r].v[j])>ret && f[r].p[j] >= l) {
            ret ^= f[r].v[j];
        }
    }
    return ret;
}
// if (f[r].p[j] < l) break; ~~~~~~~~~~~~~~~ why ?  >-<

void init(int n) {
    // for (int i=1; i<=n; i++){
    //     for (int j=0; j<31; j++){
    //         f[i].p[j] = 0;
    //         f[i].v[j] = 0;
    //     }
    // }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        // init(n+m);
        for (int i=1; i<=n; i++){
            cin >> a[i];
            add(i,a[i]);
        }
        int lastans = 0;
        for (int i=1; i<=m; i++){
            int tp; cin >> tp;
            if (tp == 0) {
                int l, r;
                cin >> l >> r;
                l ^= lastans;
                r ^= lastans;
                l %= (n);
                r %= (n);
                l ++;
                r ++;
                if (l > r) swap(l,r);
                lastans = ask(l,r);
                cout << lastans << endl;
            }
            else {
                int x;
                cin >> x;
                x ^= lastans;
                n++;
                add(n,x);
            }
        }
    }
    return 0;
}
