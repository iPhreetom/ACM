// CF 979C Walking the Route
// 图论 dfs
// 树分块
// 知识点：
// 	组合数的多次运用
// 	爆long long是难以预料的事情：
// 		此题，树的大小是3*10^5
// 		但……n*n-1 你懂的，这个地方结果是10^10以上，以后注意运算时的int或者longlong溢出
//
// 	联通图的子图求法（son数组）
// 	熟练掌握求树型 子图大小的求法
// 		因为是树，所以可以通过选取任意一个点作为根开始求子图大小


#include<bits/stdc++.h>
using namespace std;

long long n,u,v;
vector<vector<long long> > e(312345);
long long xs,ys,x,y;
long long book[312345];
long long son[312345];

long long dfs(long long n){
	book[n] = 1;
	son[n] = 1;
	for(long long v : e[n]){
		if(book[v] == 0){
			son[n] += dfs(v);
		}
	}

	return son[n];
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>x>>y;
	for(long long i=1;i<n;i++){
		cin>>u>>v;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	long long ans;
	dfs(x);
	ys = son[y];
	memset(book,0,sizeof(book));
	memset(son,0,sizeof(son));
	dfs(y);
	xs = son[x];


	cout<<n*(n-1)-xs*ys<<endl;
	return 0;
}
