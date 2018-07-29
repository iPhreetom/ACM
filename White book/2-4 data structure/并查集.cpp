/*并查集-实现代码*/
int rank[maxn];
int par[maxn];

//初始化
void init(int n){
	//所有元素的根都是自己
	//树的高度为0
	for(int i=0;i<n;i++){
		par[i] = i;
		rank[i] = 0;
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

	if(rank[x] < rank[y]){
		par[x] = y; //意味着x接在了y的下面
		//rank[y] = max(rank[x]+1,rank[y]);
	}
	else{
		par[y] = x;
		rank[x] = max(rank[y]+1,rank[x]);
	}
}
