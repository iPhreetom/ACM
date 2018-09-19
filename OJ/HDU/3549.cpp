// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<pair<int,int> > mp[212345];
int n,t,m,c;
int per[212345];

void init(){
	for (int i=0; i<212345; i++){
	    mp[i].clear();
	}
}

bool bfs(int s,int e){
	bool vis[2123];
	memset(vis,0,sizeof(vis));

	queue<int> que;
	que.push(s);
	per[s]=-1;
	while(!que.empty()){
		int t = que.front();
		que.pop();
		for (int i=0; i<mp[t].size(); i++){
			int &v = mp[t][i].first;
			int &c = mp[t][i].second;
		    if(!vis[v]&&c){
				vis[v]=1;
				per[v]=t;
				if(v == e){

				}
			}
		}
	}
	return false;
}

void max_flow(){
	int minn = 1e14;
	while(bfs(1,n)){
		for(int i=n;i!=-1;i=per[i]){
			minn = min(minn,mp[i])
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		init();
		cin>>n>>m;
		for (int i=0; i<m; i++){
		    int v,u,c;
			cin>>v>>u>>c;
			mp[v].push_back(make_pair(u,c));
			mp[u].push_back(make_pair(v,0));
		}
		max_flow();
	}
	return 0;
}
