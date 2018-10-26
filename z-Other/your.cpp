// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> mp[2123456];
vector<int> v;
int n;
int dis[2123456];
bool vis[2123456];
int fa[2123456];
int s,e;
int mx = 0;

inline void bfs_s(int s0){
	queue<int> que;
	que.push(s0);

	dis[s0] = 1;
	while(!que.empty()){
		int &t = que.front();
		for (int i=0; i<mp[t].size(); i++){
			if(dis[mp[t][i]] == 0){
				dis[mp[t][i]] = dis[t] + 1;
				que.push(mp[t][i]);
				if(dis[mp[t][i]] > mx){
					s = mp[t][i];
					mx = dis[mp[t][i]];
				}
			}
		}
		que.pop();
	}
}

inline void bfs_e(int s){
	queue<int> que;
	que.push(s);

	mx = 0;
	dis[s] = 1;
	while(!que.empty()){
		int &t = que.front();
		for (int i=0; i<mp[t].size(); i++){
			if(dis[mp[t][i]] == 0){

				fa[mp[t][i]] = t;
				dis[mp[t][i]] = dis[t] + 1;
				que.push(mp[t][i]);
				if(dis[mp[t][i]] > mx){
					e = mp[t][i];
					mx = dis[mp[t][i]];
				}

			}
		}
		que.pop();
	}
}

bool bfs_c(int mid){
	// memset(dis,0x3f,sizeof(dis));
	for (int i=1; i<=n; i++){
		dis[i] = 0x3f3f3f3f;
	}

	dis[s] = 1;
	dis[e] = 1;

	mid++;
	queue<int> que;
	que.push(e);
	que.push(s);

	int mx = 0;
	while(!que.empty()){
		int &t = que.front();
		for (int i=0; i<mp[t].size(); i++){
			if(dis[mp[t][i]] > dis[t]+1){
				// cout<<"mx = "<<mx<<endl;
				dis[mp[t][i]] = dis[t] + 1;
				que.push(mp[t][i]);
				if(dis[mp[t][i]] > mx){
					mx = dis[mp[t][i]];
				}
			}
		}
		que.pop();
	}

	// cout<<"mx = "<<mx<<endl;
	if(mx > mid)return 0;
	else return 1;
}

signed main(){
	// ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		cin>>n;

		// init
		for (int i=1; i<=n; i++){
			mp[i].clear();
		}
		v.clear();

		for (int i=1; i<=n-1; i++){
			int v,u;
			cin>>v>>u;
			mp[v].push_back(u);
			mp[u].push_back(v);
		}

		if(n == 2){
			cout<<"0 1 2"<<endl;
			continue;
		}
		s = 0, e = 0;

		mx = 0;
		// memset(dis,0,sizeof(dis));
		for (int i=1; i<=n; i++){
		    dis[i] = 0;
		}
		bfs_s(1);

		mx = 0;
		// memset(dis,0,sizeof(dis));
		for (int i=1; i<=n; i++){
		    dis[i] = 0;
		}
		bfs_e(s);

		fa[s] = -1;
		for (int i=e; i!=-1 ; i=fa[i]){
			v.push_back(i);
		}

		int l = (int)v.size()/3-2;
		if(l < 0)l = 1;
		int r = v.size();

		while(l+1<r){
			int mid = l+(r-l)/2;
			int s = v[mid];
			int e = v[(int)v.size()-mid-1];
			if(bfs_c(mid)){
				r = mid;
			}
			else{
				l = mid;
			}
		}

		if(v[v.size()-1-l] == v[l]){
			cout<<l<<' '<<v[l]<<' '<<v[v.size()-l]<<endl;
		}
		else cout<<l<<' '<<v[l]<<' '<<v[v.size()-1-l]<<endl;
	}
	return 0;
}
