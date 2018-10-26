#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<int> mp[112345];
vector<int> rmp[112345];

bool ico[112345];
bool kuang[112345];

int dis[112345];
int d[112345];

queue<int> que;

bool vis[112345];
int mnico[112345];
int mnkuang[112345];

queue<int> rque;

inline void rbfs(int v,int state,int mxdis){
	// set<int> s;
	// s.insert(v);

	rque.push(v);
	int dis = 0;
	if(state == 1){
		mnico[v] = 0;
	}
	else{
		mnkuang[v] = 0;
	}

	while(!rque.empty()){
		dis++;
		if(state == 1){
			int t = rque.front();
			rque.pop();

			for(int i=0;i<rmp[t].size();i++){
				int &u = rmp[t][i];
				if(mnico[u] > dis){
					mnico[u] = dis;
					rque.push(u);
					// s.insert(u);
				}
			}
		}
		else{
			int t = rque.front();
			rque.pop();

			for(int i=0;i<rmp[t].size();i++){
				int &u = rmp[t][i];
				if(mnkuang[u] > dis){
					mnkuang[u] = dis;
					rque.push(u);
					// s.insert(u);
				}
			}
		}
	}
}

inline void bfs(){
	que.push(1);
	dis[1] = 0;
	vis[1] = 1;
	memset(vis,0,sizeof(vis));

	while(!que.empty()){
		int v = que.front();
		que.pop();
		for (int i=0; i<mp[v][i]; i++){
			int &u = mp[v][i];
			if(!vis[u]){
				vis[u] = 1;
				dis[u] = dis[v]+1;
				que.push(u);
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<112345;i++){
		dis[i] = 1e8;
	}
	for(int i=0;i<112345;i++){
		mnico[i] = 1e8;
	}
	for(int i=0;i<112345;i++){
		mnkuang[i] = 1e8;
	}

	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		ico[t] = 1;
	}

	for(int i=0;i<k;i++){
		int t;
		cin>>t;
		kuang[t] = 1;
	}

	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=0;j<t;j++){
			int u;
			cin>>u;
			mp[i].push_back(u);
			rmp[u].push_back(i);
		}
	}

	bfs();
	for (int i=1; i<=n; i++){
		if(ico[i]){
			rbfs(i,1,1);
		}
		if(kuang[i]){
			rbfs(i,2,1);
		}
	}

	int ans = 1e7;
	int tp = ans;
	for(int i=1;i<=n;i++){
		ans = min(ans,mnico[i]+mnkuang[i]+dis[i]);
	}


	if(ans == tp){
		cout<<"impossible"<<endl;
	}
	else{
		cout<<ans<<endl;
	}


	return 0;
}
