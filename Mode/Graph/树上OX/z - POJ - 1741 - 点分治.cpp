#include<bits/stdc++.h>
using namespace std;

const int maxn = 11000;
const in t maxnm  = 21111;

bool vis[maxn];
vector<int> mp[maxn];
int n, k;

void init() {
	memset(vis,0,sizeof(vis));
}
 struct CenterTree {
	int n;
	int ans;
	int siz;
	int son[maxn];
	void dfs(int u,int pa) {
		son[u] = 1;
		int res = 0;
		for (int i=0; i<mp[u].size(); i++){
		    int &v = mp[u][i].first;
			int &w = mp[u][i].second;
			dfs(v, u);
			son[u] += son[v];

		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	return 0;
}
