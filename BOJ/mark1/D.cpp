#include<bits/stdc++.h>
using namespace std;

const int maxn = 1234567;

int n,m;
int p[maxn][2]; // 保存 编号为i 的灯的状态
int r[maxn]; // 保存？ <<<<<<<

struct Tgraph{
	struct Tedge{
		int son;//边的 儿子 <<<<<
		Tedge* pre; // 链表结构？ <<<<<<

		void add(int s, Tedge *p){ // 内置函数,用于建立 新的边
			son = s;
			pre = p;
		}
	};
	Tedge *now[maxn]; // 建立一个集合  <<<<<<<
	Tedge edge[maxn];// 建立一个边的集合,估计来保存 门与开关的关系？  <<<

	int tot;// total <<<<<

	void clear(){
		tot = 0; //清除的作用个是什么？ <<<<<
		memset(now,0,sizeof(now)); // now为什么可以用0来赋值 ? <<<<
	}

	void add(int x,int y){
		edge[++tot].add(y,now[x]); //tot增加了2，然后，分别加入了 边加入了[y,now[x]]；
		edge[++tot].add(x,now[y]); // 调用了edge 中的add函数，son 等于x， pre = now[y]；
	}
};

Tgraph G;//建立一张图

void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>r[i]; //输入的是灯的初始状态
	}
	for(int i=1;i<=m;i++){
		int s;//开关控制的灯个数
		for(int j=1;j<=s;j++){
			int x ;//开关编号
			cin>>x;
			if(!p[x][0])p[x][0] = i; //因为一开始p[x][0]的值一定为1
			else p[x][1] = i; //所以此处只是简单的把两个开关的编号记下来
		}
	}
}

int cl[maxn];
bool dfs(int x,int c){
	cl[x] = c;// ACM猜变量的游戏 <<<<<<<<<<<<<<<
	int asd = 1-c; /// 这个和……C的关系氏 asd + c = 1;<<<<<<<<<<<<<<<<<

	// for(Tgraph::Tedge *p = G,now[x] ; p ; p = p->pre){//链表，或者叫做邻接矩阵？<<<<<<<<<<<<<
	// 	if(cl[p->son] != -1 && cl[p->son] != asd){// 存在子节点为-1的情况么？那么一般情况氏什么
	// 		return false;
	// 	}
	// }
	/*
看不懂看不懂，弃了
【】

	*/

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
