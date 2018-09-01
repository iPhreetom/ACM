#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

map< pair<int,int> , int > mp;
vector<pair<int,int>> a[112345];
int u,v,c;
int n,m,k;
int node[112345][11];
const int maxn = 1e18;
bool vis[112345];
void init(){
	memset(vis, 0, sizeof  vis);
	for(int i=0;i<112345;i++){
		a[i].clear();
	}
	mp.clear();
	for (int i=0; i<112345; i++){
	    for (int j=0; j<=10; j++){
	        node[i][j] = maxn;
	    }
	}
}

void bfs(int p){
	queue<int> que;
	que.push(1);
	for(int i = 0; i <= k; i++)
	    node[1][i] = 0;

	while(!que.empty()){
		int u = que.front();
		bool si = 0;
		vis[u] = 0;
		que.pop();
        for(int i = 0; i < a[u].size(); i++)
        {
        	int to = a[u][i].first;
        	if(node[to][0] > node[u][0] + a[u][i].second)
        	    node[to][0] = node[u][0] + a[u][i].second, si = 1;
        	//node[to][k] = min(node[to][k], node[u][k - 1]);
        	for(int j = 1; j <= k; j++)
        	{
        		if(node[to][j] > node[u][j] + a[u][i].second)
        		    node[to][j] = node[u][j] + a[u][i].second, si = 1;
        		if(node[to][j] > node[u][j - 1])
        		    node[to][j] = node[u][j - 1], si = 1;
			}
			if(!vis[to] && si)
			{
				vis[to] = 1;
				que.push(to);
			}
			//cout<< u << ' ' << to << ' ' << node[to][k] << endl;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;cin>>tt;
	while(tt--){
		init();

		cin>>n>>m>>k;
		for (int i=0; i<m; i++){
			cin>>u>>v>>c;
			if(mp.count(make_pair(u,v)) == 0)mp[make_pair(u,v)] = c;
			else mp[make_pair(u,v)] = min(mp[make_pair(u,v)],c);
		}

		for(auto i=mp.begin();i!=mp.end();i++){
			const int &u = i->first.first;
			const int &v = i->first.second;
			int &c = i->second;
			a[u].push_back(make_pair(v,c));
		}

		bfs(1);
		int ans = node[n][0];
		for(int i= 1; i <= k; i++)
		    ans = min(ans, node[n][i]);
		cout << ans << endl;
	}
	return 0;
}
