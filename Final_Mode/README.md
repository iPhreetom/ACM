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
- [x] 莫队
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
- [x] 矩阵快速幂
- [ ] 高斯消元
- [x] 线性基
- [ ] 单纯形
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
## 动态规划
    return (int)(__int128(a) * b % MOD);
}



int inv(int x) { return powMod(x, MOD - 2); }
// EXGCD
// gcd(a, p) = 1时有逆元
int inv(int a, int p) {
    int x, y;
    int d = exgcd(a, p, x, y);
    if (d == 1) return (x % p + p) % p;
    return -1;
}

// 逆元打表
int inv[MAXN];

void initInv() {
    inv[1] = 1;
    for (int i = 2; i < MAXN - 5; i++) {
        inv[i] = 1int * (MOD - MOD / i) * inv[MOD % i] % MOD;
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
```c++
struct E {
    int to, cp;
    E(int to, int cp): to(to), cp(cp) {}
};

struct Dinic {
    static const int M = 1E5 * 5;
    int m, s, t;
    vector<E> edges;
    vector<int> G[M];
    int d[M];
    int cur[M];

    void init(int n, int s, int t) {
        this->s = s; this->t = t;
        for (int i = 0; i <= n; i++) G[i].clear();
        edges.clear(); m = 0;
    }

    void addedge(int u, int v, int cap) {
        edges.emplace_back(v, cap);
        edges.emplace_back(u, 0);
        G[u].push_back(m++);
        G[v].push_back(m++);
    }

    bool BFS() {
        memset(d, 0, sizeof d);
        queue<int> Q;
        Q.push(s); d[s] = 1;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int& i: G[x]) {
                E &e = edges[i];
                if (!d[e.to] && e.cp > 0) {
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return d[t];
    }

    int DFS(int u, int cp) {
        if (u == t || !cp) return cp;
        int tmp = cp, f;
        for (int& i = cur[u]; i < G[u].size(); i++) {
            E& e = edges[G[u][i]];
            if (d[u] + 1 == d[e.to]) {
                f = DFS(e.to, min(cp, e.cp));
                e.cp -= f;
                edges[G[u][i] ^ 1].cp += f;
                cp -= f;
                if (!cp) break;
            }
        }
        return tmp - cp;
    }

    int go() {
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof cur);
            flow += DFS(s, INF);
        }
        return flow;
    }
} DC;
```
## 费用流
``` c++
// 内置的全局变量: 点个数n
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>

const int maxn = 4020;
const int INF = 0x3f3f3f3f;
using namespace std;
int n;
typedef struct ss {
    int to, cap, cost, rev;
    ss(int a, int b, int c, int d) {
        to = a;   cap = b;
        cost = c; rev = d;
    }
} st;

typedef pair<int, int> P;
int h[maxn], dis[maxn];
int pv[maxn], pe[maxn];
vector<st> G[maxn];

void init() {
    for(int i = 0; i < maxn; i++) {
        G[i].clear();
        h[i] = 0;
    }
}

void add(int f, int t, int c, int cost) {
    G[f].push_back(st(t, c, cost, G[t].size()));
    G[t].push_back(st(f, 0, -cost, G[f].size() - 1));
}

int mincostflow(int s, int t, int &f) {
    int res = 0;
    while(f > 0) {
        priority_queue<P, vector<P>, greater<P> > q;
        q.push(P(0, s));
        fiint(dis, dis + maxn, INF);
        dis[s] = 0;
        while(!q.empty()) {
            P p = q.top(); q.pop();
            int l = p.first, v = p.second;
            if(dis[v] < l) continue;
            for(int i = 0; i < G[v].size(); i++) {
                st &e = G[v][i];
                if(e.cap > 0 && dis[e.to] > dis[v] + e.cost + h[v] - h[e.to]) {
                    dis[e.to] = dis[v] + e.cost + h[v] - h[e.to];
                    pv[e.to] = v;
                    pe[e.to] = i;
                    q.push(P(dis[e.to], e.to));
                }
            }
        }
        if(dis[t] == INF) break;
        for(int v = 0; v < n + 2; v++) h[v] += dis[v];
        int d = f;
        for(int u = t; u != s; u = pv[u]) {
            d = min(d, G[pv[u]][pe[u]].cap);
        }
        f -= d;
        res += d * h[t];
        for(int u = t; u != s; u = pv[u]) {
            st &e = G[pv[u]][pe[u]];
            e.cap -= d;
            G[u][e.rev].cap += d;
        }
    }
    return res;
}


signed main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'

	// int res = maxn-1;
	// int s = maxn-2;
	// int t = maxn-3;
	int T;
	cin >> T;
	while(T--){
		int k;
		cin >> n >> k;
		init();

		vector<int> v(n+1);
		for (int i=1; i<=n; i++){
			cin>>v[i];
		}
		int res = 2*n+1;
		int s = 2*n+2;
		int t = 2*n+3;
		add(res, s, k, 0);
		for (int i=1; i<=n; i++){
			add(i, i+n, 1, -v[i]);
			add(s, i, 1, 0);
			add(i+n, t, 1, 0);
		    for (int j=i+1; j<=n; j++){
				if (v[i] <= v[j]) {
					add(i+n, j, 1, 0);
				}
		    }
		}
		n = n*2+10;
		int f = k;
		cout << -mincostflow(res,t,f) << endl;
	}
    return 0;
}

```
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
            // ans=max(ans,1int*cnt[i]*len[i]);
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
