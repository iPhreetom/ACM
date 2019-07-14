# 模板目录

---
## 比赛知识
- [ ] 赛前检查

## 数据结构
- [x] 并查集
- [x] Set Map STL
- [ ] 区间修改查询线段树
- [ ] 动态开点线段树
- [ ] 权值线段树
- [ ] 主席树
- [ ] splay
- [ ] 莫队
- [ ] CDQ分治
- [ ] 苗卡尔树
- [ ] 线段树合并
- [ ] 长链剖分
- [ ] 点分治
- [ ] 树链剖分
- [ ] 虚树

---
## 图论
- [x] 最短路dijkstra
- [x] LCA
- [x] 拓扑排序
- [x] 网络流
- [x] tarjin强连通分量
- [x] 2-sat
- [x] 最大独立集最大团
- [ ] 奇环树
- [ ] 欧拉路径
- [ ] 二分图匹配
- [ ] 最小树形图

---
##数学
- [ ] 逆元，快速幂
- [ ] 矩阵快速幂
- [ ] 高斯消元
- [ ] 线性基
- [ ] 单纯性
- [ ] 容斥定理
- [ ] 生成函数
- [ ] EXGCD
- [ ] 中国剩余定理
- [ ] 原根
- [ ] BSGS
- [ ] 自适应辛普森积分
- [ ] 插值与快速插值
- [ ] 线性筛
- [ ] 莫比乌斯反演
- [ ] FFT
- [ ] FWT
- [ ] NTT

---
## 字符串
- [ ] Hash
- [ ] Tire
- [ ] KMP、EXKMP
- [ ] AC自动机
- [ ] Manacher
- [ ] 回文自动机
- [ ] 后缀数组
- [ ] 后缀自动机

---

## 计算机和
- [ ] 点与线
- [ ] 多边形
- [ ] 圆
- [ ] 三维几何


---
#数据结构
---

## 并查集
``` c++
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5; // temp

int p[maxn];

void init() {
	for (int i=0; i<maxn; i++){
		p[i] = i;
	}
}

int getparent(int v) {
	int root = v;
	while (p[root] != root) {
		root = p[root];
	}
	while (p[v] != v) {
		int temp = p[v];
		p[v] = root;
		v = temp;
	}
	return root;
}

void unite(int u, int v) {
	v = getparent(v);
	p[v] = getparent(u);
}

bool ifsame(int u,int v) {
	return getparent(u) == getparent(v);
}
```

### 学习笔记

- poj 食物链 分析 
  - 通过分析题目里的相对关系，可以把一个动物的关系分成三类，我自己，吃我的，被我吃的。然后每次，合并和判断的时候，维护这三个关系就好了。可以用三倍的数组实现，也可以通过结构体实现。
- poj Ubi 宗教信仰 模板题
  - 通过unite来合并学生群体
  - 通过set或者一个桶排序类似物，实现统计有多少个不同的数字
- poj 修电脑 暴力 建模
  - n^n的把修好的电脑并在一起
- poj 非典传播 模板题 
  - 如果分成多个组（连通块）
  - 那么，每个连通块内的元素unite一下
  - 就可以得到最终有多少个连通块
- hdu 判断树 树的性质
  - 树只有一个入度为0的点
  - 边数等于点数-1（可以通过这个判断：是否有环，是否连通）
  - ​

