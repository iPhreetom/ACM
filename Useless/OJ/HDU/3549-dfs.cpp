// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<pair<int,int> > mp[212345];
int n,t,m,c;
int per[212345];
int* lineper[212345];
int* rlineper[212345];

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
		// cout<<"t = "<<t<<endl;
		que.pop();
		for (int i=0; i<mp[t].size(); i++){
			int &v = mp[t][i].first;
			int &c = mp[t][i].second;

		    if(!vis[v]&&c!=0){
				vis[v]=1;
				que.push(v);
				per[v]=t;
				lineper[v]=&c;

				for(int j=0;j<mp[v].size();j++){
					if(mp[v][j].first == t){
						rlineper[v] = &mp[v][j].second;
						break;
					}
				}

				if(v == e){
					return true;
				}
			}
		}
	}
	return false;
}


void max_flow(){
	static int index = 0;
	// cout<<" = "<<index<<endl;
	int ans = 0;
	while(bfs(1,n)){

		int minn = 1e14;
		for(int i=n;i!=1;i=per[i]){
			minn = min(minn,*lineper[i]);
		}
		ans += minn;

		for(int i=n;i!=1;i=per[i]){
			*lineper[i] -= minn;
			*rlineper[i] += minn;
		}
	}
	cout<<"Case "<<++index<<": "<<ans<<endl;
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
		// cout<<"t = "<<t<<endl;
		max_flow();
	}
	return 0;
}
