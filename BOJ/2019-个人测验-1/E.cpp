#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	vector<vector<int>> mp(n);
	for (int i=1; i<=n-1; i++) {
	    int u,v;
		cin >> u >> v;
		u--;
		v--;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}

	vector<int> cnt(n, 1);
	vector<int> fa(n, -1);
	vector<int> depth(n ,0);

	function<int(int,int,int)> dfs;
	dfs = [&](int v, int f, int d) -> int {
		fa[v] = f;
		depth[v] = d;
		for (int i=0; i<mp[v].size(); i++) {
			if(mp[v][i] != f) {
				cnt[v] += dfs(mp[v][i], v, d+1);
			}
		}
		return cnt[v];
	};
	dfs(0, -1, 0);

	vector<vector<int>> times(n, vector<int> (22, 0));
	for (int j=0; j<n; j++) {
		times[j][0] = fa[j];
	}
	for (int i=1; i<22; i++) {
		for (int j=0; j<n; j++) {
			if(times[j][i-1] != -1) {
				int lastone = times[j][i-1];
				times[j][i] = times[lastone][i-1];
			}
			else {
				times[j][i] = -1;
			}
		}
	}

	auto lca = [&](int v, int u) -> int {
		if (depth[u] > depth[v]) swap(u, v);

		int temp = depth[v] - depth[u];
		int dif = temp;
		for (int i=0; (1<<i)<=temp; i++) {
			if (temp&(1<<i)) { // 逐位消除
				v = times[v][i];
			}
		}

		if (v == u) return u;

		for (int i=(int)log2(n*1.0); i>=0; i--) {
			if (times[u][i] != times[v][i]) {
				v = times[v][i];
				u = times[u][i];
			}
		}
		return times[u][0];
	};

	auto getans = [&](int u,int v) -> int {
		if (com == u || com == v) {
			int dif = abs(depth[u] - depth[v]);
			if(dif % 2 == 1) {
				return 0;
			}
			else {

			}
		}
	};
	int m;
	cin >> m;
	while(m -- ) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		int com = lca(v,u);

		// one case
		if (depth[u] == depth[v]) {
			int ans = 0;

		}
		else if(depth[u] > depth[v]){

		}
		else { // depth[v] > depth[u]

		}
	}
	return 0;
}
