// POJ - 2195
#pragma GCC optimize(2)
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN_ 5050
#define endl '\n'
#define INF 0x3f3f3f3f
#define P pair<int,int>
using namespace std;
struct edge{ int to,cap,cost,rev;};
int n,m,flow,s,t,cap,res,cost,from,to,h[MAXN_];
std::vector<edge> G[MAXN_];
int dist[MAXN_],prevv[MAXN_],preve[MAXN_]; // 前驱节点和对应边
inline void add()
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
} // 在vector 之中找到边的位置所在!

inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){if(c=='-')flag=1;    c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?-x:x;
}

inline void min_cost_flow(int s,int t,int f)
{
    fill(h+1,h+1+n,0);
    while(f > 0)
    {
        priority_queue<P,vector<P>, greater<P> > D;
        memset(dist,INF,sizeof dist);
        dist[s] = 0; D.push(P(0,s));
        while(!D.empty())
        {
            P now = D.top(); D.pop();
            if(dist[now.second] < now.first) continue;
            int v = now.second;
            for(int i=0;i<(int)G[v].size();++i)
            {
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
                {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    D.push(P(dist[e.to],e.to));
                }
            }
        }
        // 无法增广 ， 就是找到了答案了！
        if(dist[t] == INF) break;
        for(int i=1;i<=n;++i) h[i] += dist[i];
        int d = f;
        for(int v = t; v != s; v = prevv[v])
            d = min(d,G[prevv[v]][preve[v]].cap);
        f -= d; flow += d;
        res += d * h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
}



inline int dis(auto &pa,auto &pb){
	return abs(pa.first-pb.first) + abs(pa.second-pb.second);
}

void init()
{
	for (int i=0; i<MAXN_; i++){
		G[i].clear();
	}
	memset(dist,0,sizeof(dist));
	memset(prevv,0,sizeof(prevv));
	memset(preve,0,sizeof(preve));
	memset(h,0,sizeof(h));
}


int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	s = 10;
	t = 20;
	from = 10;
	to = 20;
	cap = 2;
	cost = 4;

	add();
	swap(from,to);
	add();
	min_cost_flow(s,t,INF);
	cout<<"res = "<<res<<endl;
	cout<<"flow = "<<flow<<endl;
	printf("%d\n", res);

	int n,m;
	while(1){
		init();
		cin>>n>>m;
		if(n == 0 && m == 0)break;
		string mp[MAXN_];
		for (int i=0; i<n; i++){
			cin>>mp[i];
		}

		vector<pair<int,int>> hum;
		vector<pair<int,int>> home;

		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				if(mp[i][j] == 'm'){
					hum.push_back(make_pair(i+1,j+1));
				}
			}
		}
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				if(mp[i][j] == 'H'){
					home.push_back(make_pair(i+1,j+1));
				}
			}
		}

		s = 0;
		t = n*2 + 1;

		for (int i=0; i<home.size(); i++){
			from = n+i+1;
			to = t;
			cap = 2;
			cost = 0;
			add();
			swap(from,to);
			add();
		}

		for (int i=0; i<hum.size(); i++){
			from = s;
			to = i+1;
			cap = 2;
			cost = 0;
			add();
			swap(from,to);
			add();
			for (int j=0; j<home.size(); j++){
				from = i+1;
				to = n+j+1;
				cap = 2;
				cost = dis(hum[i],home[j]);
				add();
				swap(from,to);
				add();
			}
		}

		flow = 0;
		res = 0;
		min_cost_flow(s,t,INF);
		// cout<<res<<endl;
		printf("%d\n",res);
	}
	return 0;
}

// int n,m;
// cin>>n>>m;
// H.init(n+2);
// int u,v,c;
// while(m--){
// 	cin>>u>>v>>c;
// 	H.add_edge(u,v,1,c);
// 	H.add_edge(v,u,1,c);
// }
//
// H.add_edge(0, 1, 2, 0);
// H.add_edge(n, n+1, 2, 0);

// cout<<H.Mincost(0, n+1)<<endl;
