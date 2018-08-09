const int maxn = 1e5+5;
int head[maxn]; // 起点编号 ——> 空间位置
int ver[maxn]; // 空间位置 ——> 重点编号
int next[maxn]; // 空间位置 ——> 下一个空间位置
int edge[maxn]; // 空间位置 ——> 值
int tot; // 空间位置递增

void add(int x,int y,int v){// 在头部插入
	next[++tot] = head[x] , head[x] = tot;
	ver[tot] = y;
	edge[tot] = v;
}

// 遍历x所能够到达的所有边
for(int i=head[x];i;i=next[i]){
	int y = ver[i];
	int v = edge[i];
}

// DFS
for(int i=head[x];i;){
	i = head[ver[i]];
}
