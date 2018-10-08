// POJ 1511（dijkstra 的反向“多源最短路”）
// HDU 1535
// 	一句话描述：
// 		dijkstra 的反向“多源最短路”
// 	知识点：
// 		在终点唯一的题目中
// 		把所有有向边反向，再从终点算单源最短路
// 		就可以得到所有的点前往终点的最短路
// 	碎碎念：
// 		妈耶，以前的题目不能够使用STL不开心
// 		没有最新版本的STL加速，用起来就TLE，好烦耶
//
// 		似乎题解：
// 		要开始ACM比赛啦，有很多志愿者一起住在CSS中
// 		每天早上，他们要通过公交从CSS前往每一个公交站点，去引导参赛者乘坐公交
// 		然后晚上坐公交回来
// 		公交线路是单向的，因而去的花费和回来的花费可能不同
// 		请问每天所有志愿者公交花费最小总和是多少
// 		思路很简单呐
// 		出发时，用dijkstra算出单源最短路，做一次统计
// 		然后把所有边反向，然后再一次dijkstra，再做一次统计！

// #include<cstdio>
// #include<string.h>
// #include<iostream>
// #include<vector>
// #include<queue>
#include<bits/stdc++.h>
// #define int long long
// #define double long double
#define endl '\n'
using namespace std;
const int inf = 2e9;
const int maxn = 1000001;
typedef pair<int,int> pii;


int t;
int n,m;
vector<pair<int,int> > a[maxn];
vector<pair<int,int> > b[maxn];
int d1[maxn];
int d2[maxn];
bool vis[maxn];
// #define inf 112345678
#define maxe 1000001
#define maxv 1000001


// int d[maxv];

inline bool readint(int &num)
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}

inline void dijkstra3(int s){
	priority_queue<pii,vector<pii>,greater<pii> > que;// 从小到大
	// fill(d1,d1+n+1,inf);
	d1[s] = 0;
	que.push(make_pair(0,s));

	while(!que.empty()){
		pii p = que.top();
		que.pop();

		int &from = p.second;
		if(vis[from])continue;
		vis[from]=1;
		if(d1[from] < p.first)continue;// 此时这个节点被更新了更小的值，舍弃曾经的最小值45
		for(int i=0;i<a[from].size();i++){
			int &to = a[from][i].first;
			int &c = a[from][i].second;
			if(d1[to] > d1[from] + c){
				d1[to] = d1[from] + c;
				que.push(make_pair(d1[to],to));
			}
		}
	}
}

inline void dijkstra4(int s){
	priority_queue<pii,vector<pii>,greater<pii> > que;// 从小到大
	// fill(d1,d1+n+1,inf);
	d2[s] = 0;
	que.push(make_pair(0,s));

	while(!que.empty()){
		pii p = que.top();
		que.pop();

		int &from = p.second;
		if(vis[from])continue;
		vis[from]=1;
		if(d2[from] < p.first)continue;// 此时这个节点被更新了更小的值，舍弃曾经的最小值45
		for(int i=0;i<b[from].size();i++){
			int &to = b[from][i].first;
			int &c = b[from][i].second;
			if(d2[to] > d2[from] + c){
				d2[to] = d2[from] + c;
				que.push(make_pair(d2[to],to));
			}
		}
	}
}

inline void init(){
	// a.clear();
	// b.clear();
	// a.resize(n+1);
	// b.resize(n+1);
	for(int i=0;i<=n;i++){
		a[i].clear();
		b[i].clear();
	}
	// fill(d1,d1+n+1,inf);
	// fill(d2,d2+n+1,inf);
	for (int i=0; i<=n; i++){
		d1[i] = inf;
		d2[i] = inf;
	}
	memset(vis,0,sizeof(vis));
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// cin>>t;
	readint(t);
	while(t--){
		readint(n);
		readint(m);

		init();
		for (int i=0; i<m; i++){
		   int x,y,c;
		   // cin>>x>>y>>c;
		   readint(x);
		   readint(y);
		   readint(c);
		   a[x].push_back(make_pair(y,c));
		   b[y].push_back(make_pair(x,c));
		}

		dijkstra3(1);
		memset(vis,0,sizeof(vis));
		dijkstra4(1);

		int ans = 0;
		for (int i=2; i<=n; i++){
			ans+=d1[i];
			ans+=d2[i];
		}
		// cout<<ans<<endl;
		printf("%d\n",ans);
	}
	return 0;
}
