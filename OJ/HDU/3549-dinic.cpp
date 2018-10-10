// 多组数据的dinic模板
// 	需要memset head 数组
// 	或者head[1] = 0
//
// 题解：
// 	dinic的算法，就是用过bfs直接把每个点定义一个层次
// 	在dfs找增广路的时候，找一个深度加深的情况

#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1<<29 , N = 510 , M = 3010;
int head[N];
int Next[M];
int ver[M];// 当前点的编号
int edge[M];// 当前点的边权
int  d[M];
int n,m,s,t,tot,maxflow;
queue<int> q;

void add(int x,int y,int z){
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
	ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}// 正反建立边（运用 n^1 的性质，可以在正反两边跑

bool bfs(){// 建立层次图，不能建立说明没有增广路
	memset(d,0,sizeof(d));
	while(!q.empty())q.pop();
	q.push(s);
	d[s] = 1;
	while(!q.empty()){
		int x= q.front();
		q.pop();
		for (int i=head[x]; i; i = Next[i]){
		    if(edge[i] && !d[ver[i]]){
				q.push(ver[i]);
				d[ver[i]] = d[x] + 1;
				if(ver[i] == t){
					return 1;
				}
			}
		}
	}
	return 0;
}

int dinic(int x,int flow){
	// cout<<"x = "<<x<<endl;
	if(x == t){
		return flow;
	}
	int rest = flow ;
	int k;
	for(int i = head[x] ; i && rest ; i = Next[i]){
		if(edge[i] && d[ver[i]] == d[x] + 1){
			k = dinic(ver[i],min(rest,edge[i]));
			if(!k)d[ver[i]] = 0;// 剪枝
			edge[i] -= k;
			edge[i^1] += k;
			rest -= k;
		}
	}
	// cout<<"flow-rest = "<<flow-rest<<endl;
	return flow - rest;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	int dd = 0;
	while(cin>>n>>m){
		// cin>>n>>m;
		// cin>>s>>t;
		maxflow = 0;
		s = 1;
		t = n;
		tot = 1;
		// head[1] = 0;
		memset(head,0,sizeof(head));
		for(int i=1; i<=m; i++){
			int x,y,c;
			cin>>x>>y>>c;
			add(x,y,c);
		}
		int flow = 0;
		while(bfs()){
			// cout<<"flow = "<<flow<<endl;
			while(flow = dinic(s,inf))
			maxflow += flow;
		}
		// cout<<maxflow<<endl;
		cout<<"Case "<<dd+1<<": "<<maxflow<<endl;
		dd++;
		if(tt == dd){
			break;
		}
	}
	return 0;
}
