// CF 938 Buy a ticket
// 	一句话描述：
// 		找到每一个节点的小消耗（路径小高乘二＋演唱会门票）
// 	知识点：
// 		单源最短路dijkstra的 多源最多路写法（超级起点（d[i]有初值）

#include<bits/stdc++.h>
#define int long long
#define double long double
#define make(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii; //  first 存最短距离，second 存编号

const int inf = 2e17;
const int maxe = 212345;
const int maxv = 212345;

struct edge{
	int to,cost;
	edge(){}
	edge(int t,int c){
		this->to = t;
		this->cost = c;
	}
};

vector<vector<edge> > arr(maxe);
int v,e;
int d[maxv];
bool vis[maxv];

void dijkstra(){
	priority_queue<pii,vector<pii>,greater<pii> > que;// 从小到大
	for(int i=1;i<=v;i++){
		que.push(make_pair(d[i],i));
	}

	while(!que.empty()){
		pii p = que.top();
		que.pop();

		int from = p.second;
		if(d[p.second] < p.first)continue;
		for(int i=0;i<arr[from].size();i++){
			edge eg = arr[from][i];
			if(d[eg.to] > d[from]+eg.cost){
				d[eg.to] = d[from]+eg.cost;
				que.push(make_pair(d[eg.to],eg.to));
				// que.push(make_pair(d[eg.to], d[eg.to] ));
			}
			// if(d[arr[from][i].to] > d[from] + arr[from][i].cost){
			// 	d[arr[from][i].to] = d[from]+arr[from][i].cost;
			// 	que.push(make_pair(d[arr[from][i].to],d[arr[from][i].to]));
			// }
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>v>>e;

	for(int i=0;i<e;i++){
		int u,v,c;
		cin>>u>>v>>c;
		arr[u].push_back(edge(v,2*c));
		arr[v].push_back(edge(u,2*c));
	}

	for(int i=1;i<=v;i++){
		cin>>d[i];
	}
	dijkstra();
	for(int i=1;i<=v;i++){
		cout<<d[i];
		i != v?cout<<' ':cout<<endl;
	}

	return 0;
}


// int bfs(int index,int from,int routecost,bool first){
// 	if(first){
// 		int mn = cost[index];
// 		for(int i=0;i<mp[index].size();i++){
// 			mn = min(mn,bfs(mp[index][i].first,index,0,0) );
// 		}
// 		return mn;
// 	}else{
// 		int mn = cost[index] + routecost + 2*mp[from][index].second;
//
// 		if(2*mp[from][index].second+routecost >= routecost + cost[from])return 1e17;
// 		routecost = routecost + 2*mp[from][index].second;
//
// 		for(int i=0;i<mp[index].size();i++){
// 			if(vis.count(mp[index][i].first) == 0){
// 				vis[]
// 				mn = min(bfs(mp[index][i].first,index,routecost,0),mn);
// 			}
// 		}
// 		return mn;
// 	}
// }
