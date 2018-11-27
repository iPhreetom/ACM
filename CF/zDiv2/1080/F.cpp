// fyt
// 交互题
// 给你N个线段集合
// 然后给你K个线段
// 	这些线段会被分配进集合里
//
// 然后给你M个询问
// 询问包含a,b,x,y
// 	在集合a到b中
// 	是否存在一个线段[l,r]完全被x,y包含

#include<bits/stdc++.h>
using namespace std;

// HJT tree
const int MAXN = 300001;

// 本代码中所有数据均按从下标 1 开始存放

// 主席树中的线段树结点，sum 表示此区间内元素个数
struct node {
    int sum, l, r;
} hjt[MAXN*40];
struct S {
	int l ,r ,p;
	friend bool operator< (const S& lt, const S& rt){
		return lt.l < rt.l;
	};
}sorted[MAXN];
int a[MAXN], num;    // sorted: 离散化后的数组 num: 离散化后的数组长度
int root[MAXN], cnt;    // root: 主席树中用来保存每棵线段树树根的数组 cnt: 线段树结点数（用于数组方式动态开点）

// 查找离散化之后的下标
int GetIdx(int v) {
	S tp;
	tp.l = v;
    return lower_bound(sorted+1, sorted+1+num, tp) - sorted;
}

// 初始化
void Init() {
    cnt = 0;
}

// 创建结点
inline int CreateNode(int sum, int l, int r) {
    int idx = ++cnt;
    hjt[idx].sum = sum;
    hjt[idx].l = l;
    hjt[idx].r = r;

    return idx;
}

// 新建一棵线段树，只沿更新路径新建出较上个版本有修改的结点
// 调用参数
// root: 插入后新生成的线段树的根结点会赋值到 root 中存储
// pre_rt: 上一棵线段树的根
// pos: 本次要插入的数在线段树中的位置
// l, r: 递归参数。默认填写 1, num
void Insert(int &root, int pre_rt, int pos, int l, int r) {
    // 动态创建结点，直接根据上一个版本复制对应的结点，sum+1
    root = CreateNode(hjt[pre_rt].sum+1, hjt[pre_rt].l, hjt[pre_rt].r);
    if(l == r) return;
    int m = (l+r) >> 1;
    if(pos <= m)
        Insert(hjt[root].l, hjt[pre_rt].l, pos, l, m);
    else Insert(hjt[root].r, hjt[pre_rt].r, pos, m+1, r);
}

// 本函数适用于查询区间 [l, r] 中的第 k 小。通常需要自行变通
// 调用参数
// s, e: 要查询区间所需的两个线段树的根，如要查询区间 [l, r]，则传入 root[l-1], root[r]
// k: 要查询区间第几小
// l, r: 递归参数。默认填写 1, num
int Query(int s, int e, int k, int l, int r) {
    if(l == r) return l;
    int m = (l+r) >> 1;
    int sum = hjt[hjt[e].l].sum - hjt[hjt[s].l].sum;    // 计算左子树的元素数量
    if(k <= sum)    // 如果 k <= sum，则 k 在左子树，否则在右子树
        return Query(hjt[s].l, hjt[e].l, k, l, m);
    else return Query(hjt[s].r, hjt[e].r, k-sum, m+1, r);
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	Init();

	for (int i=1; i<=k; i++){
		int l,r,p;
		cin>>l>>r>>p;
		sorted[i].l = l;
		sorted[i].r = r;
		sorted[i].p = p;
	}
	sort(sorted+1,sorted+k+1);
	for (int i=1; i<=k; i++){
		Insert(root[i], root[i-1], GetIdx(sorted[i].p), 1, num);
	}
	num = unique(sorted+1, sorted+1+k) - (sorted+1);
	while(k--){
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		if(Query(root[GetIdx(x)], 1, n, a, b) <= y){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
