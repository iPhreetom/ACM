#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>

const int maxn = 205;
const int INF = 0x3f3f3f3f;
using namespace std;

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
int n, m, k;
int need[55][55];
int support[55][55];
int cost[55][55][55];
int sum[55];

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
        fill(dis, dis + maxn, INF);
        dis[s] = 0;
        while(!q.empty()) {
            P p = q.top(); q.pop();
            int l = p.first, v = p.second;
            if(dis[v] < l) continue;
            for(int i = 0; i < G[v].size(); i++) {
                st &e = G[v][i];
                ///printf("cap = %d\n", e.cap);
                if(e.cap > 0 && dis[e.to] > dis[v] + e.cost + h[v] - h[e.to]) {
                    dis[e.to] = dis[v] + e.cost + h[v] - h[e.to];
                    pv[e.to] = v;
                    pe[e.to] = i;
                    q.push(P(dis[e.to], e.to));
                }
            }
        }
        if(dis[t] == INF) return -1;
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


int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'

    while(cin>>n>>m>>k) {
        if(n == 0 && m == 0 && k == 0)break;
        init();
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
            init();
            for(int i=1;i<=n; i++)add(i+(th-1)*n+len1,t,need[i][th],0);
            for(int i=1;i<=m; i++)add(s,i+(th-1)*m,support[i][th],0);
            for(int i=1; i<=m; i++){
                for(int j=1; j<=n; j++){
                    add(i+(th-1)*m,j+len1+(th-1)*n,min(support[i][th],need[j][th]),cost[th][j][i]);
                }
            }
			// cout<<"sum[th] = "<<sum[th]<<endl;
            int cost = mincostflow(s, t, sum[th]);
			// cout<<"sum[th] = "<<sum[th]<<endl;
			// cout<<"cost = "<<cost<<endl;

            if(sum[th] > 0)ok = 0;
			if(!ok)break;
            sumcost += cost;
        }

        if(!ok)cout<<-1<<endl;
        else cout<<sumcost<<endl;
    }
    return 0;
}
