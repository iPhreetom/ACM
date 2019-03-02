DFS先预处理，每个节点的父亲节点和其深度
递推预处理，每个节点走2^k次后到达的节点
查询时，先把两者放在同一高度
然后，逐位消除，因为走多了肯定会走到同一节点（同一高度的性质

void dfs(int u, int pre, int d) {
	fa[u][0] = pre;
	depth[u] = d;
	for (int i=0; i<mp[u].size(); i++){
	    int &v = mp[u][i];
		if (v != pre) {
			dfs(v, u, d+1);
		}
	}
}

void init () {
	dfs(root, -1, 0); // root 为树根一般为 1
	for (int j=0; (1<<(j+1))<n, j++) {
		for (int i=0; i<n; i++){
		    if(fa[i][j] < 0) fa[i][j+1] = -1;
			else fa[i][j+1] = fa[fa[i][j]][j];
		}
	}
}

int lca(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	int dif = depth[v] - depth[u];
	for (int i=0; (1<<i)<=temp; i++) {
		if (temp&(1<<i)) { // 逐位消除
			v = fa[v][i];
		}
	}
	if (v == u) return u;
	for (int i=(int)log2(n*1.0); i>=0; i--) {
		if (fa[u][i] != fa[v][i]) {
			v = fa[v][i];
			u = fa[u][i];
		}
	}
	return fa[u][0];
}
