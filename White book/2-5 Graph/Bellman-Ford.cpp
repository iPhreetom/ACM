#include<bits/stdc++.h>
using namespace std;
/*
单源最短路问题-Bellman-Ford（有向图更新做法）
	描述：
		能够求出一点到所有点的最短路（单源）
		同样用于求一点到一个固定终点的最短路
	公式：
		变量：d[i] 为起点s到d[i]的最短路
		递推式子：d[i] = min(d[i] , d[j]+cost[j][i]);
	复杂度：
		O(V*E)
	特点：
		可以计算负边

		图中有环则设定到所有点的距离为INF，可以在有限次的循环中找到答案

		图中有负环，不能算出最短路，但是也可以O(V*E)求出负环（第v-1次更新）
*/
#define inf 112345678
#define maxe 112345
#define maxv 112345

struct edge{int from,to,cost;};
edge arr[maxv];

int d[maxv];
int v,e;

void shortest_path(int s){
	// for(int i=0;i<v;i++)d[i] = inf;
	fill(d,d+maxv,inf);
	d[s] = 0;
	while(1){
		bool update = 0;
		for(int i=0;i<e;i++){
			edge eg = arr[i];
			if(d[eg.from] != inf && d[eg.to] > d[eg.from] + eg.cost){
				d[eg.to] = d[eg.from]+eg.cost;
				update = 1;
			}
		}
		if(!update)break;
	}
}

bool find_negative_loop(){
	memset(d,0,sizeof(d));

	for(int i=0;i<v;i++){
		for(int j=0;j<e;j++){
			edge eg = arr[j];
			if(d[eg.to] > d[eg.from]+eg.cost){
				d[eg.to] = d[eg.from]+eg.cost;
				if(i == v-1)return 1;
				// 复杂度证明，在V-1次内，可以保证全部更新完成
				// 如果出现v-1次更新，说明是存在负环
			}
		}
	}

	return false;
}
