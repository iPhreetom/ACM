#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int u,v;
vector<vector<int> > mp(1123456);
bool vis[1123456];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		// if(u > v)swap(u,v);
		mp[v].push_back(u);
		mp[u].push_back(v);
	}

	/*
	第一个节点的值，通过bfs 保存不同深度的 值的大小？
		int first[1123456]l

	1、除了第一个节点以外，如果它的联通的点数如果为1，那么它一定是端点（值为0）

	2、从端点向前找？
		- 先通过bfs 确定每一个节点对于1的绝对距离

		- 把所有的端点 存进一个优先队列 ， 绝对距离大的在前面
			- 端点的答案直接赋值为 0
			- 答案数组可以先赋值为 -1

		- 从最右的端点开始向前更新答案
			- 除了端点的值，答案为最大的值的相对下标

		*- 对于每一个绝对位置，我都想知道所有的点的公共祖先是谁

	3、

	*/
	return 0;
}
