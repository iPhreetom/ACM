// CF 982C
// 图论
// 基于邻接矩形的DFS
// 涉及知识点：
// 	DFS
// 	联通图的概念
// 	联通量的概念 和 子联通大小的概念
// 	树的性质（简单）
//
// cut 的思路是：任取一点作为根，dfs 返回 每个点的子孙数（以它为根的联通图大小）
// 					易得：当子孙数为偶数时，（联通图大小为偶数）可以切掉一边

#pragma GCC diagnostic error "-std=c++11"

#include<bits/stdc++.h>
using namespace std;

int n,u,v;
vector<vector<int> > edge(112345);
bool book[112345];
long long son[112345];

int dfs(int n){
	book[n]=1;
	son[n]=1;
	for(int v : edge[n]){
		if(book[v]==0){
			son[n]+=dfs(v);
		}
	}
	return son[n];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if(n%2==1){
		cout<<"-1"<<endl;
	}
	else{
		dfs(1);
		int cnt = 0;
		for(int i=1;i<=n;i++){
			cnt+= (son[i]%2 == 0);
		}
		cnt--;
		cout<<cnt<<endl;
	}
	return 0;
}
