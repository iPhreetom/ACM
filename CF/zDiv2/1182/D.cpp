#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> mp[512345];
const int maxn = 212345;

int n;
bool vis[maxn];
int dis[maxn];
vector<int> lis;
bool fit = 0;
int ct = 0;
int node = 0;
int node2 = 0;
bool alls = 1;
set<int> st[maxn];
map<int,int> mntree;

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

void dfs2 (int v) {
	lis.push_back(v);
	if (v == node2) {
		if (!fit) {
			fit = 1;
			ct = lis[lis.size()/2];
		}
	}
	for (int i=0; i<mp[v].size(); i++){
		int &u = mp[v][i];
		if(!vis[u]) {
			vis[u] = 1;
			dfs2(u);
		}
	}
	lis.pop_back();
}

void dfs3(int v, int d) {
	st[d].insert(mp[v].size());
	int cnt = 0;
	for (int i=0; i<mp[v].size(); i++){
		int &u = mp[v][i];
		if(!vis[u]) {
			cnt++;
			vis[u] = 1;
			dis[u] = d+1;
			dfs3(u, d+1);
		}
	}
	if (cnt == 0) {
		mntree[d] ++ ;
	}
}

bool check(int v) {
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dfs3(v, 1);
	for (int i=0; i<maxn; i++) {
		if (st[i].size() > 1) {
			return -1;
		}
	}
	return 1;
}

int getcenter () {
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1] = 1;
	dfs(1, 1);
	int mx = 0;
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
			node2 = i;
			mx = dis[i];
		}
	}
	if (mx % 2 == 0) {
		return -1;
	}


	memset(vis,0,sizeof(vis));
	dfs2(node);
	// get ct
	if (check(ct) ) {
		return 1;
	}
	else {
		if (mntree.size() == 2) {
			if (mntree.begin()->second == 1) {
				if (check(mntree.begin()->first)) {
					ct = mntree.begin()->first;
					return 1;
				}
			}
		}
		return -1;
	}
}


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i=0; i<n-1; i++) {
		int u,v;
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	if (getcenter() == -1) {
		cout << -1 << endl;
	}
	else {
		cout << ct << endl;
	}
	return 0;
}
