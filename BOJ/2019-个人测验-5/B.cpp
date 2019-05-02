#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<vector<pair<int,int> > > mp(112345);
vector<bool> vis;
bool fg = 0;
void dfs(int f, int e,int c) {
	if(f == e)fg = 1;
	if(fg)return;

	for (int i=0; i<mp[f].size(); i++) {
		int &v = mp[f][i].first;
		int &cl = mp[f][i].second;
		if(cl == c && !vis[v]) {
			vis[v] = 1;
			dfs(v,e,c);
		}
	}
}

bool judge(int u,int v,int c) {
	fg = 0;
	for (int i=0; i<vis.size(); i++) {
		vis[i] = 0;
	}
	dfs(u,v,c);
	return fg;
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	vis.resize(n+5);
	for (int i=1; i<=m; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		mp[a].push_back(make_pair(b,c));
		mp[b].push_back(make_pair(a,c));
	}
	int q;
	cin >> q;
	map<pair<int,int>,int> ans;
	while (q--) {
		int v,u;
		cin >> v >> u;
		if(v>u)swap(v,u);
		if(ans.count(make_pair(u,v))!=0){
			cout << ans[make_pair(u,v)] << endl;
			continue;
		}
		int num = 0;
		for (int i=1; i<=m; i++) {
			if(judge(u,v,i)){
				num++;
			}
		}
		ans[make_pair(u,v)] = num;
		cout << num << endl;
	}
	return 0;
}
