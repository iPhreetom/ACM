// fyt
#include<bits/stdc++.h>
// #define int long long
// #define double long double
using namespace std;

const int maxn = 1e4+5;
vector<int> mp[maxn];
int n,m,x,y;
int color[maxn];
bool vis[maxn];

void init(){
	memset(color,-1,sizeof(color));
	memset(vis,0,sizeof(vis));
	for (int i=0; i<maxn; i++){
		mp[i].clear();
	}
}

bool dfs(int s){
	for (int i=0; i<mp[s].size(); i++){
	    if(!vis[mp[s][i]] && color[mp[s][i]] == -1){
			vis[mp[s][i]] = 1;
			if(color[s] == 1)color[mp[s][i]] = 2;
			if(color[s] == 2)color[mp[s][i]] = 1;
			if(dfs(mp[s][i]) == 0)return 0;
		}
		else{
			if(color[mp[s][i]] == color[s])return 0;
		}
	}
	return 1;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>n>>m>>x>>y){
		init();
		for (int i=0; i<m; i++){
		    int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		queue<int> que;
		for (int i=0; i<x; i++){
		    int t;
			cin>>t;
			color[t] = 1;
			que.push(t);
		}
		for (int i=0; i<y; i++){
			int t;
			cin>>t;
			color[t] = 2;
			que.push(t);
		}
		bool ok = 1;
		while(!que.empty()){
			if(!vis[que.front()]){
				vis[que.front()] = 1;
				if(dfs(que.front()) == 0)ok = 0;
			}
			que.pop();
		}
		for (int i=1; i<=n; i++){
			if(!vis[i]){
				if(mp[i].size() == 0)ok = 0;
				vis[i]=1;
				color[i] = 1;
				if(dfs(i) == 0)ok = 0;
			}
		}
		if(ok)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
