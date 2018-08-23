#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define duke(i,a,n) for(int i = a;i <= n;i++)
#define lv(i,a,n) for(int i = a;i >= n;i--)
#define maxn 100010
template <class T>
void read(T &x)
{
    char c;
    bool op = 0;
    while(c = getchar(),c > '9' || c < '0')
        if(c == '-') op = 1;
    x = c - '0';
    while(c = getchar(),c <= '9' && c >= '0')
        x = x * 10 + c - '0';
    if(op == 1)
        x = -x;
}
bool vis[maxn];
int n,m,s,t,k,losew,op,x,y,z,f,dis[maxn],pre[maxn],last[maxn],flow[maxn],maf,mic;
//dis最小花费;pre每个点的前驱；last每个点的所连的前一条边；flow源点到此处的流量
struct Edge
{
    int to,nxt,flow,dis;//flow流量 dis花费
	int type;
} a[maxn];
int head[maxn],len;
queue <int> q;

void add(int from,int to,int flow,int dis,int type)
{
    a[++len].nxt=head[from];
    a[len].to=to;
    a[len].flow=flow;
    a[len].dis=dis;
	a[len].type=type;
    head[from]=len;
}
bool spfa(int s,int t)
{
    memset(dis,0x7f,sizeof(dis));
    memset(flow,0x7f,sizeof(flow));
    memset(vis,0,sizeof(vis));
    q.push(s);
    vis[s]=1;
    dis[s]=0;
    pre[t]=-1;
    while (!q.empty())
    {
        int now=q.front();
        q.pop();
        vis[now]=0;
        for (int i=head[now]; i!=-1; i=a[i].nxt)
        {
            if (a[i].flow>0 && dis[a[i].to]>dis[now]+a[i].dis)//正边
            {
                dis[a[i].to]=dis[now]+a[i].dis;
                pre[a[i].to]=now;
                last[a[i].to]=i;
                flow[a[i].to]=min(flow[now],a[i].flow);//
                if (!vis[a[i].to])
                {
                    vis[a[i].to]=1;
                    q.push(a[i].to);
                }
            }
        }
    }
    return pre[t]!=-1;
}
void max_flow()
{
    while (spfa(s,t))
    {
        int now=t;
        maf+=flow[t];
        mic+=flow[t]*dis[t];
        while (now!=s)
        {
            a[last[now]].flow-=flow[t];//flow和dis容易搞混
            a[last[now]^1].flow+=flow[t];
            now=pre[now];
        }
    }
}
int main()
{
    int t;read(t);
	while(t--){
		memset(head,-1,sizeof(head));
	    len = -1;
		int q;
	    read(q);read(n);read(k);read(losew);
		//read(s);read(t);
		s = 0;
		t = 205;
	    duke(i,1,n)
	    {
	        read(x);read(y);read(z);read(op);
	        add(x,y,1,-z,op);
	        add(y,x,0,z,op);
	    }
		for (int i=1; i<=n; i++){
		    
		}
	    max_flow();
	    printf("%d %d\n",maf,mic);
	}
    return 0;
}
