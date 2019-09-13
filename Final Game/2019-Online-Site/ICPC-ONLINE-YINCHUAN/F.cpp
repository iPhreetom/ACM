// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int mp[212][212];
int val[212];
bool vis[212];
int dis[212];
int n, m;

int dk(int s,int t,int w) {
	typedef pair<int,int> pii;
	priority_queue<pii,vector<pii>,greater<pii>> que;

	que.push(make_pair(0,s));
	while(!que.empty()) {
		int	now = que.top().first;
		int u = que.top().second;
		que.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		dis[u] = now;
		for (int i=1; i<=n; i++){
			if (!vis[i] && (i==t || val[i]<=w)) {
				que.push(make_pair(now+mp[u][i],i));
			}
		}
	}
	return dis[t];
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	for (int cs=1; cs<=T; cs++) {
		cin >> n >> m;
		for (int i=1; i<=n; i++) {
			cin >> val[i];
		}
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				cin >> mp[i][j];
			}
		}
		cout << "Case #" << cs << ":" << endl;
		while(m--){
			int u,v,w;
			memset(vis,0,sizeof(bool)*(n+5));
			memset(dis,0,sizeof(int)*(n+5));
			cin >> u >> v >> w;
			cout << dk(u,v,w) << endl;
		}
	}
	return 0;
}
