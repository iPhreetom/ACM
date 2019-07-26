#include<bits/stdc++.h>
using namespace std;
/*
单源最短路问题-Dijkstra-（对Bellman修改）
	描述：
		从已知最短距离确定的顶点，更新到相邻顶点的最短路
		从队列中删除 已经更新过的最短距离的顶点
	公式：
		变量：d[i] 为起点s到d[i]的最短路
		递推式子：d[i] = min(d[i] , d[j]+cost[j][i]);
	复杂度：
		在边权一样的时候，复杂度O（E*E)
		不全部相同时：O(E*log(V))
	特点：
		因为作为 来源 的点，会不被继续考虑，所以当存在负边的时候？
*/
#define inf 112345678
#define maxe 112345
#define maxv 112345

struct edge{
	int to,cost;
};
typedef pair<int,int> pii; //  first 存最短距离，second 存编号

vector<vector<edge> > arr(maxe);

int v;
int d[maxv];

void dijkstra(int s){
	priority_queue<pii,vector<pii>,greater<pii> > que;// 从小到大
	fill(d,d+v,inf);
	d[s] = 0;
	que.push(make_pair(0,s));

	while(!que.empty()){
		pii p = que.top();
		que.pop();

		int from = p.second;
		if(d[from] < p.first)continue;// 此时这个节点被更新了更小的值，舍弃曾经的最小值45
		for(int i=0;i<arr[from].size();i++){
			edge eg = arr[from][i];
			if(d[eg.to] > d[from] + eg.cost){
				d[eg.to] = d[from]+eg.cost;
				que.push(make_pair(d[eg.to],eg.to));
			}
		}
	}
}
