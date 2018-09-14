#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int maxn = 212345;
int d1[maxn];
bool vis[maxn];
typedef pair<int,int> pii;
vector<pair<int,int> > a[maxn];
int n,m;

inline void init(){
	for(int i=0;i<=n+1;i++){
		a[i].clear();
	}
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


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		init();
		for (int i=2; i<=n; i++){
			a[i].push_back(make_pair(1,i-1));
			a[i-1].push_back(make_pair(1,i));
		}
		for (int i=0; i<m; i++){
		    int v,u;
			cin>>v>>u;
			a[u].push_back(make_pair(1,v));
			a[v].push_back(make_pair(1,u));
		}
		int s;
		cin>>s;
		dijkstra(s);
		for (int i=1; i<=n; i++){
			if(i != s){
				if(d1[i] == d1[0]){
					cout<<-1<<' ';
				}
				else{
					cout<<d1[i]<<' ';
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
