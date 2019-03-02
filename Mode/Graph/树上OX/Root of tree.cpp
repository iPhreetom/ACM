const int maxn = ;
int Num;
int num[maxn];
int mnum[maxn];
int root;
bool vis[maxn];

// 求重心时，没有标记vis
void get_root(int u, int fa) {
	mnum[u] = 0;
	num[u] = 1; // 包含自己
	for (int i=0; i<mp[u].size(); i++){
		int &v = mp[u][i].first;
		int &w = mp[u][i].second;
		if(vis[v]||v==fa)continue;
		get_center(v, u);
		mnum[u] = max(mnum[u],num[v]);
		num[u] += num[v];
	}
	mnum[u] = max(mnum[u], Num-num[u]);
	if(nnum[u] > nnum[root]) {
		root = u;
	}
}
