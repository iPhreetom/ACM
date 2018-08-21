#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int n;
int t[212345];
int to[212345];
vector<int> from[212345];
int cost ;
int vis[212345];
int ans ;
queue<int> que;

void build(int id){
	vis[id] = 3;
	// cout<<"id = "<<id<<endl;
	for (int i=0; i<from[id].size(); i++){
		build(from[id][i]);
	}
}

void dfs(int id){
	// cout<<"id = "<<id<<endl;
	vis[id]++;
	if(vis[to[id]] == 1){
		dfs(to[id]);
	}
	if(vis[to[id]] == 2){
		cost = min(cost,t[to[id]]);
		dfs(to[id]);
	}
}

void bfs(int id){
	vis[id] = 1;
	que.push(id);
	cost = 1123456789;

	while(!que.empty()){
		int tp = que.front();
		que.pop();

		vis[tp] = 1;

		if(vis[to[tp]] == 0)que.push(to[tp]);
		for (int i=0; i<from[tp].size(); i++){
			if(vis[from[tp][i]] == 0){
				que.push(from[tp][i]);
			}
		}
	}

	dfs(id);
	ans+=cost;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>t[i];
	}
	for (int i=1; i<=n; i++){
	    cin>>to[i];
		if(to[i] != i)from[to[i]].push_back(i);
	}
	// cout<<"??"<<endl;
	for (int i=1; i<=n; i++){
		if(to[i] == i){
			build(i);
			ans+=t[i];
		}
	}
	for (int i=1; i<=n; i++){
	    if(vis[i] == 0){
			bfs(i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
