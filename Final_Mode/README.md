# 模板目录


## 比赛知识
- [ ] 赛前检查
---
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
- [ ] 笛卡尔树
- [ ] 线段树合并
- [ ] 长链剖分
- [ ] 点分治
- [ ] 树链剖分
- [ ] 虚树

---
## 图论
- [ ] 最短路dijkstra
- [ ] LCA
- [ ] 拓扑排序
- [ ] 网络流
- [ ] tarjin强连通分量
- [ ] 2-sat
- [ ] 最大独立集最大团
- [ ] 奇环树
- [ ] 欧拉路径
- [ ] 二分图匹配
- [ ] 最小树形图

---
## 数学
- [ ] 逆元，快速幂
- [ ] 矩阵快速幂
- [ ] 高斯消元
- [x] 线性基
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
- [x] Tire
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


# 数据结构
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
---
## 树状数组
```c++
// 支持第k大的BIT
// 下标从1开始
struct Tbit {
    int size;
    ll t[MAXN];

    int lowbit(int x) { return x & (-x); }

    void init(int sz) {
        size = sz + 1;
        memset(t, 0, (sz + 2) * sizeof(ll));
    }

    void add(int p, ll x) {
        if (p <= 0) return;
        for (; p <= size; p += lowbit(p)) t[p] += x;
    }

    ll get(int p) {
        ll sum = 0;
        for (; p > 0; p -= lowbit(p)) sum += t[p];
        return sum;
    }

    void update(int p, ll x) { add(p, x - query(p, p)); }
    ll query(int l, int r) { return get(r) - get(l - 1); }

    int kth(ll k) {
        int p = 0;
        for (int i = 20; i >= 0; i--) {
            int p_ = p + (1 << i);
            if (p_ <= size && t[p_] < k) {
                k -= t[p_];
                p = p_;
            }
        }
        return p + 1;
    }
};
```
### 学习笔记
- hdu6318 树状数组求逆序对
	- 树状数组的每一个get，得到的都是前缀和
	- 所以可以有两种方法求出逆序对，从前往后query和直接从后往前get
---
## 区间修改线段树
```c++
#define ls (p<<1)
#define rs ((p<<1)+1)
#define mid ((l+r)>>1)
const int maxn = 3e5+7;
int a[maxn];
int ql,qr,x;

struct node{
    int mn,add;
}tree[maxn*4];

inline void pushdown(int p) {
    tree[ls].mn += tree[p].add;
    tree[rs].mn += tree[p].add;
    tree[ls].add += tree[p].add;
    tree[rs].add += tree[p].add;
    tree[p].add = 0;
}

inline void pushup(int p) {
    tree[p].mn = min(tree[ls].mn,tree[rs].mn);
}

void build(int p,int l,int r) {
    if (l == r) {
        tree[p].mn = a[r];
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}

void update(int p,int l, int r) {
    if (ql <= l && r <= qr) {
        tree[p].mn += x;
		tree[p].add += x;
		return ;
    }
    if (tree[p].add != 0) pushdown(p);
    if (ql <= mid) update(ls,l,mid);
    if (qr >= mid+1) update(rs,mid+1,r);
    pushup(p);
}

int query(int p, int l, int r) {
    if (ql <= l && r <= qr) {
        return tree[p].mn;
    }
    if (tree[p].add) pushdown(p);
    int num = 2e18;
    if (ql <= mid) num = min(num, query(ls, l, mid));
    if (qr >= mid+1) num = min(num, query(rs, mid+1, r));
    return num;
}
```
### 学习笔记
- HDU-6315-线段树-区间暴力修改-懒标记、
    - 线段树减少常数的方法：
        -用if减少少递归
        - 把ql和qr变成全局变量
    - 线段树注意事项：update的时候，留意return的位置，return即表示剪枝
---


# 数学
## 快速幂 逆元 （待做题）
``` c++
// 注意 b = 0, MOD = 1 的情况
typedef long long ll
ll powMod(ll a, ll b) {
    ll ans = 1;
    for (a %= MOD; b; b >>= 1) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

// 模数爆int时使用，带取模的乘法
ll mul(ll a, ll b) {
    ll ans = 0;
    for (a %= MOD; b; b >>= 1) {
        if (b & 1) ans = (ans + a) % MOD;
        a = (a << 1) % MOD;
    }
    return ans;
}

// O(1) - 魔法，需要测试
ll mul(ll a, ll b) {
    return (ll)(__int128(a) * b % MOD);
}



ll inv(ll x) { return powMod(x, MOD - 2); }
// EXGCD
// gcd(a, p) = 1时有逆元
ll inv(ll a, ll p) {
    ll x, y;
    ll d = exgcd(a, p, x, y);
    if (d == 1) return (x % p + p) % p;
    return -1;
}

// 逆元打表
ll inv[MAXN];

void initInv() {
    inv[1] = 1;
    for (int i = 2; i < MAXN - 5; i++) {
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
}
```
## 线性基
```c++
const int maxn = 1e6+5;
struct node {
    int p[31], v[31];
} f[maxn];
int a[maxn];

// 合并，即，把一个线性基插入另一个线性基中
void add(int i, int x) {
    for (int j=0; j<31; j++){
        f[i].p[j] = f[i-1].p[j];
        f[i].v[j] = f[i-1].v[j];
    }
    int k = i;
    for (int j=30; ~j; --j) {
        if ((x>>j)&1) {
            if (f[i].v[j]) {
                if (f[i].p[j] < k) {
                    swap(f[i].p[j],k);
                    swap(f[i].v[j],x); // swap 的时候 i 会变化， 所以位置信息要用一个新的变量维护。
                }
                x ^= f[i].v[j];
            }
            else {
                f[i].v[j] = x;
                f[i].p[j] = k;
                break;
            }
        }
    }
}

int ask(int l,int r) {
    int ret = 0;
    for (int j=30; ~j; --j) {
        if ((ret^f[r].v[j])>ret && f[r].p[j] >= l) {
            ret ^= f[r].v[j];
        }
    }
    return ret;
}
// if (f[r].p[j] < l) break; ~~~~~~~~~~~~~~~ why ?  >-<


```
### 学习笔记
- 2019-hdu-muti-1-1002
    - 题意
		0lr 求最大异或和
		1x 增加一个x到尾部
	- 思路
		线性基 + O（N）求区间抑或最大值
---
## 卡特兰数
```
应用：
    一种可以统计括号匹配个数的思路
    问题形如“求有多少种合法的序列”
方法：
    规定DP转移方式为：此状态 = 几种合法子状态相加。
    合法状态可以用矩形来辅助判断
```
### 学习笔记
- 牛客2019多校题 第一场 E题
    - 题意：
        - 有多少种长度为2*(n+m)的字符串，提取出用 n个"() 和 "m个“)(" 子序列 - 不要求连续
    - 思路
        - 二维的dp数组保存，用了i个(和j个)，可以构造出多少种不同的子序列
        - 合法状态，画个矩阵就可以知道，是两个平行的斜线，不要超过它们的情况内，都是合法的
        - 取dp[m+n][m+n]即为答案
---

# 图论
## 强联通分量
```c++

```
## 最大流

---

# 字符串
## Trie
### 代码
``` c++
// 01 Trie
struct Trie {
    int t[31 * MAXN][2], sz;

    void init() {
        memset(t, 0, 2 * (sz + 2) * sizeof(int));
        sz = 1;
    }

    void insert(int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            bool d = (x >> i) & 1;
            if (!t[p][d]) t[p][d] = sz++;
            p = t[p][d];
        }
    }
};

// 正常Trie
struct Trie {
    int t[MAXN][26], sz, cnt[MAXN];

    void init() {
        memset(t, 0, 26 * (sz + 2) * sizeof(int));
        memset(cnt, 0, (sz + 2) * sizeof(int));
        sz = 1;
    }

    void insert(const string& s) {
        int p = 0;
        for (char c : s) {
            int d = c - 'a';
            if (!t[p][d]) t[p][d] = sz++;
            p = t[p][d];
        }
        cnt[p]++;
    }
};
```

## 回文自动机
### 代码
``` c++
const int N=300005;
const int C=26;

long long ans;
string str;
int n;

struct Palindrome_Tree
{
    int next[N][C],cnt[N],fail[N],len[N];
    int tot,suf;

    // 维护额外信息
    int indexof[N];

    int newnode()
    {
        for (int i=0;i<C;i++)
            next[tot][i]=0;
        cnt[tot]=0,fail[tot]=0;
        return tot++;
    }

    void init()
    {
        tot=0;
        int p;
        len[p=newnode()]=0;
        p=fail[p]=newnode();
        len[p]=-1;
        fail[p]=p;
        suf=0;
    }

    int getfail(int x,int l)
    {
        while (str[l-1-len[x]]!=str[l])
            x=fail[x];
        return x;
    }

    int insert(int x)
    {
        int c=str[x]-'a';
        int p=getfail(suf,x);
        if (!next[p][c])
        {
            int q=newnode();
            len[q]=len[p]+2;
            fail[q]=next[getfail(fail[p],x)][c];

            next[p][c]=q;
        }
        p=next[p][c];
        cnt[p]++;
        suf=p;
        return suf;
    }

    void calc()
    {
        for (int i=tot-1;i>=0;i--)
        {
            // ans=max(ans,1ll*cnt[i]*len[i]);
			// cout << cnt[i]*len[i] << endl;
			mp[len[i]]+=cnt[i];
            cnt[fail[i]]+=cnt[i];
        }
    }
}t;
```

## manacher
### 代码
``` c++
// "aba" => "#a#b#a#"
string make(string& s) {
    string t = "#";
    for (int i = 0; i < s.size(); i++) {
        t.push_back(s[i]);
        t.push_back('#');
    }
    return t;
}

void manacher(const string& s, vector<int>& d) {
    int n = s.size();
    d.resize(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d[l + r - i], r - i);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
        d[i] = --k;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
}
```
ctrl k 0 (-level) show outline
ctrl k j 