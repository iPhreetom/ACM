#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3; // temp

int p[maxn];

void init(int n) {
	for (int i=0; i<n; i++){
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

int main () {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int cnt = 0;
    int last = 1e3;
    while (true) {
        init(last);
        cnt ++;
        // map<int,vector<int>> mp;
        set<int> s;
        map<int,int> v;
        bool flag = true;
        while (true) {
            int x,y;
            cin >> x >> y;
            if (x<0 || y<0) return 0;
            if (x == 0 && y == 0) break;
            if (ifsame(x,y)) {
                flag = 0;
            }
            v[y]++;
            unite(x,y);
            s.insert(x);
            s.insert(y);
            // mp[x].emplace_back(y);
        }
        int num = 0;
        int root = *s.begin();
        for (auto i:s) {
            if (v[i] == 0) num++;
            if (!ifsame(root,i)) {
                flag = 0;
            }
            last = i+1;
        }
        if (num != 1) flag = 0;
        if (flag) {
            cout << "Case " << cnt << " is a tree." << endl;
        }
        else {
            cout << "Case " << cnt << " is not a tree." << endl;
        }
    }
}