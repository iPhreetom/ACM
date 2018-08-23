#include<bits/stdc++.h>
#define int long long
#define double long double
#define enddl '\n'
using namespace std;
//************************************************************
//最小费用最大流算法
//SPFA求最短路
//邻接矩阵形式
//初始化:cap:容量，没有边为0
//cost:耗费，对称形式，没有边的也为0
//c是最小费用
//f是最大流
//*******************************************************
const int MAXN=250;
const int INF=0x3fffffff;
int cap[MAXN][MAXN];//容量，没有边为0
int flow[MAXN][MAXN];
//耗费矩阵是对称的，有i到j的费用，则j到i的费用为其相反数
int cost[MAXN][MAXN];
int n;//顶点数目0~n-1
int f;//最大流
int c;//最小费用
int startt,endd;//源点和汇点
bool vis[MAXN];//在队列标志
int que[MAXN];
int pre[MAXN];
int dist[MAXN];//s-t路径最小耗费
struct node{
	int b,e;
	int w,op;
	node(int b,int e,int w,int op){
		this->b = b;
		this->e = e;
		this->w = w;
		this->op = op;
	}
	node(){

	}
};
node a[250];
int p,k,losew;


bool SPFA()
{
	// cout<<"??"<<endl;
    int front=0,rear=0;
    for(int u=0;u<=n;u++)
    {
        if(u==startt)
        {
            que[rear++]=u;
            dist[u]=0;
            vis[u]=true;
        }
        else
        {
            dist[u]=INF;
            vis[u]=false;
        }
    }
    while(front!=rear)
    {
        int u=que[front++];
        vis[u]=false;
        if(front>=MAXN)front=0;
        for(int v=0;v<=n;v++)
        {
            if(cap[u][v]>flow[u][v]&&dist[v]>dist[u]+cost[u][v])
            {
                dist[v]=dist[u]+cost[u][v];
                pre[v]=u;
                if(!vis[v])
                {
                    vis[v]=true;
                    que[rear++]=v;
                    if(rear>=MAXN)rear=0;
                }
            }
        }
    }
    if(dist[endd]>=INF)return false;
    return true;
}

void minCostMaxflow()
{
    memset(flow,0,sizeof(flow));
    c=f=0;
    while(SPFA())
    {
        int Min=INF;
        for(int u=endd;u!=startt;u=pre[u])
           Min=min(Min,cap[pre[u]][u]-flow[pre[u]][u]);
        for(int u=endd;u!=startt;u=pre[u])
        {
            flow[pre[u]][u]+=Min;
            flow[u][pre[u]]-=Min;
        }
        c+=dist[endd]*Min;
        f+=Min;
		cout<<c<<endl;
    }
}





void solve(){
	// cin>>n>>m>>k>>losew;
	cin>>p>>n>>k>>losew;
	for (int i=0; i<n; i++){
		int b,e,w,op;
		cin>>b>>e>>w>>op;
		a[i] = node(b,e,w,op);
	}
	for (int i=0; i<n; i++){
	    int &from = a[i].b;
		int &to = a[i].e;
		int &cs = a[i].w;
		int &tp = a[i].op;
		cost[from][to] = -cs;
		cost[to][from] = cs;
		cap[from][to] = cap[to][from] = 1;
		for (int j=0; j<n; j++){
		    if(a[j].b >= a[i].e){
				int from = a[i].e;
				int to = a[j].b;
				if(a[j].op != a[i].op){
					cap[from][to] = 1;
					cap[to][from] = 1;
				}
				else{
					cap[from][to] = 1;
					cap[to][from] = 1;
					cost[from][to] = losew;
					cost[to][from] = -losew;
				}
			}
		}
	}
	for (int i=0; i<n; i++){
		cost[205][a[i].b] = 0;
		cost[a[i].b][205] = 0;
		cap[205][a[i].b] = 1;
		cap[a[i].b][205] = 1;

		cost[206][a[i].e] = 0;
		cost[a[i].e][206] = 0;
		cap[206][a[i].e] = 1;
		cap[a[i].e][206] = 1;
	}
	cost[205][0] = 0;
	cost[0][205] = 0;
	cap[205][0]=k;
	cap[0][205]=k;

	startt = 0;
	endd = 206;
	minCostMaxflow();
	cout<<c<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
