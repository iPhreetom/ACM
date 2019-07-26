#include<bits/stdc++.h>
using namespace std;

const int maxn = 200;
int ans[maxn][maxn];
int fa[maxn];

void init () {
	for (int i=0; i<maxn; i++) {
		fa[i] = i;
	}
}

int getfa(int v) {
	int root = v;
	while(fa[root] != root) {
		root = fa[root];
	}
	while(fa[v] != v) {
		int temp = fa[v];
		fa[v] = root;
		v = temp;
	}
	return root;
}

void unite(int u, int v) {
	fa[getfa(u)] = getfa(v);
}



int main () {
	typedef pair<int,pair<int,int>> pii;
	priority_queue<pii,vector<pii>,greater<pii>> que;
	init();
	for (int i=1; i<=5; i++) {
		for (int j=i+1; j<=5; j++) {
			cout << i << " -- " << j << " weight: " ;
			int w;
			cin >> w;
			que.push(make_pair(w,make_pair(i,j)));
		}
	}
	int ans = 0;
	while (!que.empty()) {
		pii p = que.top();
		que.pop();
		int w = p.first;
		int u = p.second.first;
		int v = p.second.second;
		if (getfa(u) == getfa(v)) continue;
		else {
			ans += w;
			unite(u,v);
			cout << "use: " << u << " " << v << endl;
		}
	}
	cout << "The sum is : " << ans << endl;
	return 0;
}
