#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

//map< pair<int,int> , int > mp;
//vector<pair<int,int>> a[112345];
struct test{
	int first, second;
	test *next;
}*a[2123456], pool[5123456];
int u,v,c, pl;
int n,m,k;
int dis[2123456];
const int maxn = 1e18;
bool vis[2123456];
void init(){
	pl = 0;
	memset(vis, 0, sizeof  vis);
//	for(int i=0;i<112345;i++){
//		a[i].clear();
//	}
///	mp.clear();
	for (int i=0; i<=n * (k + 1) + k; i++){
		a[i] = NULL;
	        dis[i] = maxn;
	}
}
/*
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
        for(test *i = a[u]; i != NULL; i=i->next)
        {
        	int to = i->first;
        	if(node[to][0] > node[u][0] + i->second)
        	    node[to][0] = node[u][0] + i->second, si = 1;
        	//node[to][k] = min(node[to][k], node[u][k - 1]);
        	for(int j = 1; j <= k; j++)
        	{
        		if(node[to][j] > node[u][j] + i->second)
        		    node[to][j] = node[u][j] + i->second, si = 1;
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
*/
struct cmp
{
     bool operator()(int a,int b)
     {
        return dis[a]>dis[b];
    }
};
priority_queue<int,vector<int>,cmp> Q;
//bool vis[2123456];
void dijkstra()
{
	for(int i= (k + 1); i <= (k + 1) + k; i++)
	{
		//cout << i / (k + 1) << ' ' << i % (k +1 ) << ' ' << dis[i] << endl;
	Q.push(i);
    //vis[s]=1;
    dis[i]=0;

	}

    while(!Q.empty())
    {
        int u=Q.top();
        Q.pop();
        if(vis[u]) continue;
        //cout << u /(k + 1) << u % (k + 1)<< ' ' << dis[u]<<endl;
        vis[u]=1;
        for(test *i = a[u]; i != NULL;i = i ->next)
        //for(int i=head[u];i;i=next[i])
        {
            int v=i->first, co=i->second;
            if(!vis[v]&&dis[v]>dis[u]+co)
            {
                dis[v]=dis[u]+co;
                Q.push(v);
            }
        	//cout << u /(k + 1) << u % (k + 1) << ' ' << v / (k + 1) << v %(k + 1) << ' ' << co <<' ' << dis[v]<< endl;
        }
    }
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;cin>>tt;
	while(tt--){

		cin>>n>>m>>k;
		init();
		/*for (int i=0; i<m; i++){
			cin>>u>>v>>c;
			if(mp.count(make_pair(u,v)) == 0)mp[make_pair(u,v)] = c;
			else mp[make_pair(u,v)] = min(mp[make_pair(u,v)],c);
		}

		for(auto i=mp.begin();i!=mp.end();i++){
			const int &u = i->first.first;
			const int &v = i->first.second;
			int &c = i->second;
			a[u].push_back(make_pair(v,c));
		}*/
		for(int i = 0; i < m; i++)
		{
			cin>>u>>v>>c;
			for(int j = 0; j <= k; j++)
			{
				int un = u * (k + 1) + j;
				int vn = v * (k + 1) + j;
				test *tmp = &pool[++pl];
			    tmp->first = vn;
			    tmp->second = c;
			    tmp->next = a[un];
			    a[un] = tmp;
			}
			for(int j = 1; j <= k; j++)
			{
				int un = u * (k + 1) + j - 1;
				int vn = v * (k + 1) + j;
				test *tmp = &pool[++pl];
			    tmp->first = vn;
			    tmp->second = 0;
			    tmp->next = a[un];
			    a[un] = tmp;
			}
		}
		dijkstra();
		int ans = dis[n * (k + 1)];
		//for(int i=  (k + 1); i <= n * (k + 1) + k; i++)
		//    cout << i / (k + 1) << ' ' << i % (k +1 ) << ' ' << dis[i] << endl;
		for(int i= n * (k + 1); i <= n * (k + 1) + k; i++)
		    ans = min(ans, dis[i]);
		cout << ans << endl;
	}
	return 0;
}
