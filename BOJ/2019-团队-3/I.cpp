// fyt
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
#define INF 1123456
struct E {
    int to, cp;
    E(int to, int cp): to(to), cp(cp) {}
};

struct Dinic {
    static const int M = 1E4 * 5;
    int m, s, t;
    vector<E> edges;
    vector<int> G[M];
    int d[M];
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

    int DFS(int u, int cp) {
        if (u == t || !cp) return cp;
        int tmp = cp, f;
        for (int& i = cur[u]; i < G[u].size(); i++) {
            E& e = edges[G[u][i]];
            if (d[u] + 1 == d[e.to]) {
                f = DFS(e.to, min(cp, e.cp));
                e.cp -= f;
                edges[G[u][i] ^ 1].cp += f;
                cp -= f;
                if (!cp) break;
            }
        }
        return tmp - cp;
    }

    int go() {
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof cur);
            flow += DFS(s, INF);
        }
        return flow;
    }
} DC;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,p;
	cin >> n >> m >> p;

	DC.s = 1;
	DC.t = 1+(p+1)+m+n+1;
	DC.m = 0;

	for (int i=1; i<=n; i++){
		int k; cin >> k;
		int ps = 1+(p+1)+m+i;
		for (int j=1; j<=k; j++){
			int u; cin >> u;
			int eg = 1+(p+1)+u;
			DC.addedge(eg, ps, 1);
		}
		DC.addedge(i, DC.t, 1);
	}

	set<int> s;
	for (int i=1; i<=m; i++){
		s.insert(i);
	}
	for (int i=1; i<=p; i++){
		int l; cin >> l;
		for (int j=1; j<=l; j++){
			int u;
			cin >> u;
		}
	}
	return 0;
}
