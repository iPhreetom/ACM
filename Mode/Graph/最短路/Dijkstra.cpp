#include<bits/stdc++.h>
using namespace std;


const int maxn = 212345;
int d1[maxn];
bool vis[maxn];
typedef pair<int,int> pii;
vector<pair<int,int> > a[maxn];


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

		// if(d1[from] < p.first)continue;// 此时这个节点被更新了更小的值，舍弃曾经的最小值

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
