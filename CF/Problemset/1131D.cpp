#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;

	int all = n + m;
	vector<int> fa(all);

	auto findfa = [&](int x) -> int {
		int tp = x;
		while(fa[tp] != tp) {
			tp = fa[tp];
		}
		int root = tp;
		fa[x] = root;
		while(fa[x] != root) {
			tp = fa[x];
			fa[x] = root;
			x = tp;
		}
		return root;
	};

	auto unite = [&](int a, int b) {
		int x = findfa(a);
		int y = findfa(b);

		if(x != y) {
			fa[x] = y;
			// may have the order
		}
	};

	for (int i=0; i<all; i++) {
		fa[i] = i;
	}

	vector<vector<int>> mp(all);
	vector<int> deg(all, 0);
	vector<string> s(n);

	for (int i=0; i<n; i++) {
		cin >> s[i];
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if(s[i][j] == '=') {
				unite(i, j+n);
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
		    int u = findfa(i);
			int v = findfa(j+n);
			if(s[i][j] == '>') {
				mp[v].push_back(u);
				deg[u]++;
			}
			else if(s[i][j] == '<'){
				mp[u].push_back(v);
				deg[v]++;
			}
		}
	}

	vector<int> val(n+m, 0);
	vector<bool> vis(n+m, 0);
	queue<int> que;
	for (int i=0; i<n+m; i++) {
		if(deg[i] == 0) {
			que.push(i);
			val[i] = 1;
			vis[i] = 1;
		}
	}

	while(!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i=0; i<mp[u].size(); i++) {
			int v = mp[u][i];
			deg[v]--;
			if(deg[v] == 0) {
				que.push(mp[u][i]);
				vis[v] = 1;
				val[v] = val[u] + 1;
			}
		}
	}

	for (int i=0; i<n+m; i++) {
		if(!vis[i]) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	for (int i=0; i<n; i++) {
		cout << val[findfa(i)] << ' ';
	}
	cout << endl;
	for (int i=n; i<n+m; i++) {
	    cout << val[findfa(i)] << ' ';
	}
	cout << endl;
	return 0;
}
