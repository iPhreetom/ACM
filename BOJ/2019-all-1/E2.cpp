#include <iostream>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
#define int long long

typedef long long ll;
const int N=10500;
const int inf=0x3f;
bool vis[N];

struct edge{
int u,v;
int cap, flow, cost, id;
edge() {}
edge(int from,int to,int c,int f,int co, int id):u(from),v(to),cap(c),flow(f),cost(co),id(id){}
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

    void add(int u,int v,int cap,int cost, int id=0){
        es.push_back(edge(u, v, cap, 0, cost,id));
        es.push_back(edge(v, u, 0, 0, -cost,id));
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
			//if(es[p[u]].flow==es[p[u]].cap)
			// vis[es[p[u]].id]=1;
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

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;

	H.init(2*n+20);
	vector<int> be(n+1);
	vector<int> len(n+1);
	vector<int> val(n+1);
	for (int i=1; i<=n; i++){
		cin >> be[i] >> len[i] >> val[i];
	}

	map<int,int> mp;
	for (int i=1; i<=n; i++) {
		mp[be[i]] = 0;
		mp[be[i]+len[i]] = 0;
	}
	int cnt = 0;
	for (auto &x : mp) {
		x.second = ++cnt;
	}
	for (int i=0; i<=cnt; i++) {
		if (i==0||i==cnt) H.add(i,i+1,k,0,0);
		else H.add(i,i+1,k*10+10,0,0);
	}
	for (int i=1; i<=n; i++) {
		int x = mp[be[i]];
		int y = mp[be[i]+len[i]];
		H.add(x,y,1,-val[i],i);
	}

	int origin = n;
	int f = k;
	H.Mincost(0,cnt+1,f);
	for (int i=0; i<H.es.size(); i+=2){
		// cout<<"H.es[i].id = "<<H.es[i].id<<endl;
		// cout<<"H.es[i].cap = "<<H.es[i].cap<<endl;
		// cout<<"H.es[i].flow = "<<H.es[i].flow<<endl;
		if (H.es[i].id>0 && H.es[i].cap==H.es[i].flow) vis[H.es[i].id]=1;
	}
	for (int i=1; i<=origin; i++) {
		cout << vis[i] << ' ';
	}cout << endl;
}
