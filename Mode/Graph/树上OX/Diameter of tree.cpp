// const int maxn = 212345;
// vector<int> mp[maxn];
// int dis[maxn];
// bool vis[maxn];

void dfs (int v, int d) {
	for (int i=0; i<mp[v].size(); i++){
		int &u = mp[v][i];
		if(!vis[u]) {
			vis[u] = 1;
			dis[u] = d+1;
			dfs(u, d+1);
		}
	}
}

int getcenter () {
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1] = 1;
	dfs(1, 1);

	int mx = 0;
	int node = 0;
	for (int i=1; i<=n; i++){
		if(dis[i] > mx) {
			node = i;
			mx = dis[i];
		}
	}

	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[node] = 1;
	dfs(node, 1);
	mx = 0;
	for (int i=1; i<=n; i++){
		if(dis[i] > mx) {
			node = i;
			mx = dis[i];
		}
	}
	vector<int> lis;

}
