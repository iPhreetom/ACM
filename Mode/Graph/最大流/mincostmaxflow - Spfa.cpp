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
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n,m;
    cin>>n>>m;
    H.init(n+2);
    int u,v,c;
    while(m--){
        cin>>u>>v>>c;
        H.add(u,v,1,c);
        H.add(v,u,1,c);
    }

    H.add(0, 1, 2, 0);
    H.add(n, n+1, 2, 0);

    int flow = 0;
    cout<<H.Mincost(0, n+1, flow)<<endl;

  return 0;

}
