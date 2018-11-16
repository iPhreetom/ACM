// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
#include<bits/stdc++.h>
using namespace std;

const int maxn = 312345;
int d[maxn];
bool vis[maxn];
int front[maxn];
int num[maxn];
bool used[maxn];
int edge[maxn];

typedef pair<int,int> pii;
vector<pair<int,pair<int,int> > > a[maxn];


inline void init(){
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
}



inline void dijkstra(int s){
	priority_queue<pii,vector<pii>,greater<pii> > que;// 从小到大
	// fill(d,d+n+1,inf);
	d[s] = 0;
	que.push(make_pair(0,s));

	while(!que.empty()){
		pii p = que.top();
		que.pop();

		int &from = p.second;
		if(vis[from])continue;
		vis[from]=1;
		if(d[from] < p.first)continue;// 此时这个节点被更新了更小的值，舍弃曾经的最小值45
		for(int i=0;i<a[from].size();i++){
			int &to = a[from][i].first;
			int &c = a[from][i].second.first;
			int &number = a[from][i].second.second;
			if(d[to] > d[from] + c){
				d[to] = d[from] + c;

				num[front[to]]--;

				used[edge[to]] = 0;
				edge[to] = number;
				used[number] = 1;

				front[to] = from;
				num[from]++;
				que.push(make_pair(d[to],to));
			}
		}
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1; i<=m; i++){
		int u,v,c;
		cin>>u>>v>>c;
		a[v].push_back(make_pair(u,make_pair(c,i)));
		a[u].push_back(make_pair(v,make_pair(c,i)));
	}

	for (int i=1; i<=n; i++){
		sort(a[i].begin(),a[i].end());
	}

	init();
	dijkstra(1);

	if(k >= n-1){
		cout<<n-1<<endl;
		for (int i=1; i<=m; i++){
			if(used[i]){
				cout<<i<<' ';
			}
		}
		cout<<endl;
	}
	else{
		queue<int> que;
		for (int i=1; i<=m; i++){
			if(used[i] && ){
				que.push_back(i);
			}
		}
	}

	return 0;
}
