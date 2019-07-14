#include<iostream>
#include<vector>
#define int long long
#define endl '\n'
using namespace std;

const int maxn = 1e5;
int p[maxn];

void init(int n) {
    for (int i = 0; i < n; i++){
        p[i] = i;
    }
}

int getparent(int v) {
	int root = v;
	while (p[root] != root) {
		root = p[root];
	}
	while (p[v] != v) {
		int temp = p[v];
		p[v] = root;
		v = temp;
	}
	return root;
}

void unite(int u, int v) {
	v = getparent(v);
	p[v] = getparent(u);
}

bool ifsame(int u,int v) {
	return getparent(u) == getparent(v);
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        init(n);
        for (int i=0; i<m; i++) {
            int k;
            cin >> k;
            int r;
            cin >> r;
            for (int j=1; j<k; j++) {
                int t;
                cin >> t;
                unite(r,t);
            }
        }
        int ans = 1;
        for (int i=1; i<n; i++) {
            if(ifsame(0,i)) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
