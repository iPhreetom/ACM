#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

priority_queue<int,vector<int>,greater<int> > que;
bool vis[212345];
vector<int> mp[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	vector<int> ans;

	cin >> n >> m;
	for (int i=1; i<=m; i++){
		int u,v;
		cin >> u >> v;
		mp[v].push_back(u);
		mp[u].push_back(v);
	}

	que.push(1);
	vis[1] = 1;

	while(!que.empty()) {
		int v = que.top();
		ans.push_back(v);
		que.pop();
		for (int i=0; i<mp[v].size(); i++){
			int &u = mp[v][i];
			if(!vis[u]){
				vis[u] = 1;
				que.push(u);
			}
		}
	}
	for (int i=0; i<ans.size(); i++){
		cout << ans[i] << ' ';
	}cout << endl;
	return 0;
}
