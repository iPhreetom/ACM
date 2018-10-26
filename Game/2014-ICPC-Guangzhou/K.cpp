// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 33;
int d1[maxn];
bool vis[maxn];
typedef pair<int,int> pii;
vector<pair<int,int> > a[maxn];
int mp[33][33];

inline void init(){
	memset(d1,0x3f,sizeof(d1));
	memset(vis,0,sizeof(vis));
}

inline void dijkstra(int s){
	priority_queue<pii,vector<pii>,greater<pii> > que;// 从小到大
	// fill(d1,d1+n+1,inf);
	d1[s] = 0;
	que.push(make_pair(0,s));

	while(!que.empty()){
		pii p = que.top();
		que.pop();

		int &from = p.second;
		if(vis[from])continue;
		vis[from]=1;
		if(d1[from] < p.first)continue;// 此时这个节点被更新了更小的值，舍弃曾经的最小值45
		for(int i=0;i<a[from].size();i++){
			int &to = a[from][i].first;
			int &c = a[from][i].second;
			if(d1[to] > d1[from] + c){
				d1[to] = d1[from] + c;
				que.push(make_pair(d1[to],to));
			}
		}
	}
}
int n,m;

signed main(){
    // ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while(1){
        init();
        cin>>n>>m;
        for (int i=1; i<=n; i++){
            a[i].clear();
        }

        if(n == 0 && m == 0){
            break;
        }

        while(m--){
            int u,v,c;
            cin>>u>>v>>c;
            a[v].push_back(make_pair(u,c));
            a[u].push_back(make_pair(v,c));
        }

        // for (int i=1; i<=n; i++){
        //     if(!a[i].empty()){
        //         sort(a[i].begin(),a[i].end());
        //         for (int j=0; j<a[i].size(); j++){
        //             swap(a[i][j].first,a[i][j].second);
        //         }
        //     }
        // }

        // memset(mp,0x3f,sizeof(mp));
        // while(m--){
        //     int u,v,c;
        //     cin>>u>>v>>c;
        //     mp[v][u] = mp[u][v] = min(c,mp[u][v]);
        // }
        //
        // for (int i=1; i<=n; i++){
        //     for (int j=1; j<=n; j++){
        //         if(mp[i][j] != d1[maxn-1]){
        //             a[i].push_back(make_pair(j,mp[i][j]));
        //         }
        //     }
        // }
        //
        //



        dijkstra(1);
        int mn = d1[n];
        bool findit = 0;
        for (int i=2; i<n; i++){
            init();
            d1[i] = -12;
            vis[i] = 1;
            dijkstra(1);


            int t = d1[n];
            if(t == d1[maxn-1]){
                findit = 1;
                cout<<"Inf"<<endl;
                break;
            }
            mn = max(t,mn);
        }
        if(!findit)cout<<mn<<endl;
    }
    return 0;
}
