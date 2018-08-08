

#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<vector<pair<int,int>>> mp(11234);
int n;
int d[11234];
bool vis[11234];
int ans[11234];
int start,endpoint;

void init(){
	mp.clear();
	memset(ans,0,sizeof(ans));
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
}

void dfs(int n,int dis){
	vis[n] = 1;
	d[n] = dis;
	for(int i=0;i<mp[n].size();i++){
		if(!vis[mp[n][i].first]){
			 dfs(mp[n][i].first,dis+mp[n][i].second);
		}
	}
	return ;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>n){
		init();
		for (int i=2; i<=n; i++){
			int f,c;
			cin>>f>>c;
			mp[f].push_back(make_pair(i,c));
			mp[i].push_back(make_pair(f,c));
		}

		dfs(1,0);
		int mxdis = 0;
		for (int i=1; i<=n; i++){
		    if(d[i] > mxdis){
				mxdis = d[i];
				start = i;
			}
		}

		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		dfs(start,0);
		mxdis = 0;
		for (int i=1; i<=n; i++){
			ans[i] = d[i];
			if(d[i] > mxdis){
				mxdis = d[i];
				endpoint = i;
			}
		}

		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		dfs(endpoint,0);
		for (int i=1; i<=n; i++){
			ans[i] = max(ans[i],d[i]);
			cout<<ans[i]<<'\n';
		}

	}

	return 0;
}
