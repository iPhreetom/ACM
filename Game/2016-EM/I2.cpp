#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 0x3f3f3f3f;
queue<int> que;
queue<int> rque;
int d[212345];
int d1[212345];
int d2[212345];
bool vis[212345];
bool iron[212345];
bool coal[212345];
vector<int> mp[212345];
vector<int> rmp[212345];

inline void rbfs(int v,int tp){
	if(tp == 1){
		rque.push(v);
		while(!rque.empty()){
			int t = rque.front();
			rque.pop();
			for (int i=0; i<rmp[t].size(); i++){
				int &u = rmp[t][i];

				if(iron[u]){
					d1[u] = 0;
				}
				else if(d1[u] > d1[t]+1){
					d1[u] = d1[t]+1;
					rque.push(u);
				}
			}
		}
	}
	else{
		rque.push(v);
		while(!rque.empty()){
			int t = rque.front();
			rque.pop();

			for (int i=0; i<rmp[t].size(); i++){
				int &u = rmp[t][i];
				if(coal[u]){
					d2[u] = 0;
				}
				else if(d2[u] > d2[t]+1){
					d2[u] = d2[t]+1;
					rque.push(u);
				}
			}
		}
	}
}

void bfs(){
	que.push(1);
	vis[1] = 1;
	d[1] = 0;

	while(!que.empty()){
		int v = que.front();
		// cout<<"v = "<<v<<endl;

		if(iron[v]){
			d1[v] = 0;
			rbfs(v,1);
		}
		if(coal[v]){
			d2[v] = 0;
			rbfs(v,2);
		}

		que.pop();
		for (int i=0; i<mp[v].size(); i++){
			int &u = mp[v][i];
			if(!vis[u]){
				vis[u] = 1;
				d[u] = d[v]+1;
				que.push(u);
			}
		}
	}

}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	memset(d1,0x3f,sizeof(d1));
	memset(d2,0x3f,sizeof(d2));
	int n,m,k;
	cin>>n>>m>>k;
	
	for (int i=0; i<m; i++){
		int t;
		cin>>t;
		iron[t] = 1;
	}
	for (int i=0; i<k; i++){
	    int t;
		cin>>t;
		coal[t] = 1;
	}
	for (int i=1; i<=n; i++){
		int num ; cin>>num;
		while(num--){
			int u;cin>>u;
			mp[i].push_back(u);
			rmp[u].push_back(i);
		}
	}
// 5 2 2
// 2 3
// 4 5
// 1 2
// 1 3
// 1 4
// 1 5
// 1 4
	bfs();
	long long mn = INF;
	for (int i=1; i<=n; i++){
		if(d[i] == INF || d1[i] == INF || d2[i] == INF)continue;
		mn = min(mn,(long long)d[i]+(long long)d1[i]+(long long)d2[i]);
	}
	if(mn == INF){
		cout<<"impossible"<<endl;
	}
	else cout<<mn<<endl;
	// cout<<"mn = "<<mn<<endl;

	return 0;
}
