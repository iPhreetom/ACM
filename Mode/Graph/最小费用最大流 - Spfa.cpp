#include <iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef long long ll;
typedef int Type;
const int N=1005;
const Type inf=0x3f3f3f3f;

struct edge{
  int u,v;
  Type cap, flow, cost;
  edge() {}
  edge(int from,int to,int c,int f,int co):u(from),v(to),cap(c),flow(f),cost(co){}
};

struct MCMF{
  int n,m;
  vector<edge>es;
  vector<int>G[N];
  int inq[N];//是否在队列中
  Type d[N];//SPFA时总费用
  int p[N];//上一条弧
  Type a[N];//可改进量

  void init(int n){
    this->n=n;
    for(int i=0; i<n; i++)G[i].clear();
    es.clear();
  }

  void add_edge(int u,int v,Type cap,Type cost){
    es.push_back(edge(u, v, cap, 0, cost));
    es.push_back(edge(v, u, 0, 0, -cost));
    m=es.size();
    G[u].push_back(m-2);
    G[v].push_back(m-1);
  }

  bool spfa(int s,int t,Type& flow,Type& cost){
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

  Type Mincost(int s,int t){
    Type flow=0, cost=0;
    while(spfa(s,t,flow,cost));
    return cost;
  }
}H;


int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n,m;
  cin>>n>>m;
  H.init(n+2);
  int u,v,c;
  while(m--){
    cin>>u>>v>>c;
    H.add_edge(u,v,1,c);
    H.add_edge(v,u,1,c);
  }

  H.add_edge(0, 1, 2, 0);
  H.add_edge(n, n+1, 2, 0);

  cout<<H.Mincost(0, n+1)<<endl;

  return 0;

}
