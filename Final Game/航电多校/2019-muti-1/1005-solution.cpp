// fyt
#include<bits/stdc++.h>
#define int long long
// #define double long double
#define endl '\n'
using namespace std;

const long long INF = 2e18;

struct E {
    int to, cp;
    E(int to, int cp): to(to), cp(cp) {}
};

struct Dinic {
    static const int M = 1e5+5;
    int m, s, t;
    vector<E> edges;
    vector<int> G[M];
    long long d[M];
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

    long long DFS(int u, long long cp) {
        if (u == t || !cp) return cp;
        long long tmp = cp, f;
        for (int& i = cur[u]; i < G[u].size(); i++) {
            E& e = edges[G[u][i]];
            if (d[u] + 1 == d[e.to]) {
                f = DFS(e.to, min(cp, (long long)e.cp));
                e.cp -= f;
                edges[G[u][i] ^ 1].cp += f;
                cp -= f;
                if (!cp) break;
            }
        }
        return tmp - cp;
    }

    long long go() {
        long long flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof cur);
            flow += DFS(s, INF);
        }
        return flow;
    }
} DC;

const int maxn = 11234;
long long d1[maxn];
bool vis[maxn];
typedef pair<int,int> pii;
vector<pair<int,int> > mp[maxn];


inline void init(int n){
	memset(d1,0x3f,sizeof(d1));
	memset(vis,0,sizeof(vis));
    for (int i=0; i<=n; i++){
        mp[i].clear();
    }
}

inline void dijkstra(int s){
	priority_queue<pii,vector<pii>,greater<pii> > que;// 从小到大
	d1[s] = 0;
	que.push(make_pair(0,s));

	while(!que.empty()){
		pii p = que.top();
		que.pop();

		int &from = p.second;
		if(vis[from])continue;
		vis[from]=1;

		for(int i=0;i<mp[from].size();i++){
			int &to = mp[from][i].first;
			int &c = mp[from][i].second;
			if(d1[to] > d1[from] + c){
				d1[to] = d1[from] + c;
				que.push(make_pair(d1[to],to));
			}
		}
	}
}

void dfs(int u, int f) {
    vis[u] = true;
    for (int i=0; i<mp[u].size(); i++){
        int v = mp[u][i].first;
        int cost = mp[u][i].second;
        if (v == f) continue;
        // cout<<"v = "<<v<<endl;
        // cout<<"d1[v] = "<<d1[v]<<endl;
        if (d1[v] == d1[u]+cost) {
            DC.addedge(u, v, cost);
            if (!vis[v]) dfs(v,u);
        }
    }
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n,m;
		cin >> n >> m;

        init(n);
        DC.init(n,1,n);

		for (int i=0; i<m; i++){
			int u,v,c;
			cin >> u >> v >> c;
			if (u == n) continue;
			if (v == 1) continue;
            mp[u].push_back(make_pair(v,c));
		}

        dijkstra(1);
        memset(vis,0,sizeof(vis));
        dfs(1,-1);
        cout << DC.go() << endl;
	}
	return 0;
}
