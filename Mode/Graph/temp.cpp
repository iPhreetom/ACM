#include <iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef long long ll;
const int N=5500;
const int inf=0x3f3f3f3f;

struct edge{
int u,v;
int cap, flow, cost;
edge() {}
edge(int from,int to,int c,int f,int co):u(from),v(to),cap(c),flow(f),cost(co){}
};

struct MCMF{
    int n,m;
    vector<edge>es;
    vector<int>G[N];
    int inq[N];//是否在队列中
    int d[N];//SPFA时总费用
    int p[N];//上一条弧
    int a[N];//可改进量

    void init(int n){
        this->n=n;
        for(int i=0; i<n; i++)G[i].clear();
        es.clear();
    }

    void add(int u,int v,int cap,int cost){
        es.push_back(edge(u, v, cap, 0, cost));
        es.push_back(edge(v, u, 0, 0, -cost));
        m=es.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }

    bool spfa(int s,int t,int& flow,int& cost){
        memset(inq, 0, sizeof(inq));
        for(int i=0; i<n; i++)d[i]=inf;
        d[s]=0;inq[s]=1;p[s]=0;a[s]=inf;

        queue<int>q;
        q.push(s);
        while(!q.empty()){
            int u=q.front();q.pop();inq[u]=0;
            for(int i=0; i<G[u].size(); i++){
                edge& e=es[G[u][i]];
                int v=e.v;
                if(e.cap>e.flow && d[v]>d[u]+e.cost){ //在新流下考虑最小费用
                    d[v]=d[u]+e.cost;
                    a[v]=min(a[u], e.cap-e.flow);
                    p[v]=G[u][i];
                    if(!inq[v]){ inq[v]=1; q.push(v);}
                }
            }
        }
        if(d[t]==inf)return false;
        flow+=a[t],cost+=a[t]*d[t];
        int u=t;
        while(u!=s){
            es[p[u]].flow+=a[t];
            es[p[u]^1].flow-=a[t];
            u=es[p[u]].u;
        }
        return true;
    }

    int Mincost(int s,int t,int &flow ){
        int cost=0;
        while(spfa(s,t,flow,cost));
        return cost;
    }
}H;

int n, m, k;
int need[55][55];
int support[55][55];
int cost[55][55][55];
int sum[55];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'

    while(cin>>n>>m>>k) {
        if(n == 0 && m == 0 && k == 0)break;
        memset(sum,0,sizeof(sum));

        int s=0;
        int len1 = m*k;
        int len2 = n*k;
        int t = len1+len2+1;

        for(int i=1;i<=n;i++){
            for(int j = 1; j <= k; j++){
                cin>>need[i][j];
                sum[j] += need[i][j];
            }
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=k; j++){
                cin>>support[i][j];
            }
        }

        for(int th=1;th<=k;th++){
            for(int i=1; i<=n;i++){
                for(int j=1; j<=m; j++){
                    cin>>cost[th][i][j];
                }
            }
        }


        int sumcost = 0;
        bool ok = 1;
        for(int th=1; th<=k; th++){
            H.init(2*(n+m)*k+10);
            for(int i=1;i<=n; i++)H.add(i+(th-1)*n+len1,t,need[i][th],0);
            for(int i=1;i<=m; i++)H.add(s,i+(th-1)*m,support[i][th],0);
            for(int i=1; i<=m; i++){
                for(int j=1; j<=n; j++){
                    H.add(i+(th-1)*m,j+len1+(th-1)*n,min(support[i][th],need[j][th]),cost[th][j][i]);
                }
            }

            int flow = 0;
            int cost = H.Mincost(s,t,flow);
            if(flow < sum[th])ok = 0;

			if(!ok)break;
            sumcost += cost;
        }

        if(!ok)cout<<-1<<endl;
        else cout<<sumcost<<endl;
    }
    return 0;
}
