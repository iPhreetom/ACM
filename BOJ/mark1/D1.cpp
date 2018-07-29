#include<bits/stdc++.h>
using namespace std;

const int maxn = 1234567;

////////////////////////
/*并查集-实现代码*/
int rk[2*maxn];
int par[2*maxn];

//初始化
void init(int n){
	//所有元素的根都是自己
	//树的高度为0
	for(int i=1;i<=n;i++){
		par[i] = i;
		rk[i] = 0;
	}
}

//查询树的根
int find(int x){
	if(par[x] == x){
		return x;
	}
	else{
		return par[x] = find(par[x]);//递归查找
	}
}

// 查询是否在同一集合
bool same(int x,int y){
	return find(x) == find(y);
}

// 合并x,y的所属集合
void unite(int x,int y){
	x = find(x);
	y = find(y);

	if(rk[x] < rk[y]){
		par[x] = y; //意味着x接在了y的下面
		//rk[y] = max(rk[x]+1,rk[y]);
	}
	else{
		par[y] = x;
		rk[x] = max(rk[y]+1,rk[x]);
	}
}
//////////////////

int n,m,a[maxn];
int state[maxn][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t,s;
	for(int i=1;i<=m;i++){
		cin>>s;
		for(int j=1;j<=s;j++){
			cin>>t;
			if(!state[t][0])state[t][0] = i;
			else state[t][1] = i;
		}
	}

	init(n*2);

	for(int t=1;t<=n;t++){
		if(a[t] == 1){
			unite(state[t][0],state[t][1]);
			unite(state[t][0]+m,state[t][1]+m);
		}
		else{
			 unite(state[t][1]+m,state[t][0]);
			 unite(state[t][0]+m,state[t][1]);
		}
	}

	for(int i=1;i<=m;i++){
		if(same(i,i+m)){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
