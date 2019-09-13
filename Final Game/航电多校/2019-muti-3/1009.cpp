#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>

const int maxn = 4020;
const int INF = 0x3f3f3f3f;
using namespace std;
int n;
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
                if(e.cap > 0 && dis[e.to] > dis[v] + e.cost + h[v] - h[e.to]) {
                    dis[e.to] = dis[v] + e.cost + h[v] - h[e.to];
                    pv[e.to] = v;
                    pe[e.to] = i;
                    q.push(P(dis[e.to], e.to));
                }
            }
        }
        if(dis[t] == INF) break;
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


signed main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'

	// int res = maxn-1;
	// int s = maxn-2;
	// int t = maxn-3;
	int T;
	cin >> T;
	while(T--){
		int k;
		cin >> n >> k;
		init();

		vector<int> v(n+1);
		for (int i=1; i<=n; i++){
			cin>>v[i];
		}
		int res = 2*n+1;
		int s = 2*n+2;
		int t = 2*n+3;
		add(res, s, k, 0);
		for (int i=1; i<=n; i++){
			add(i, i+n, 1, -v[i]);
			add(s, i, 1, 0);
			add(i+n, t, 1, 0);
		    for (int j=i+1; j<=n; j++){
				if (v[i] <= v[j]) {
					add(i+n, j, 1, 0);
				}
		    }
		}
		n = n*2+10;
		int f = k;
		cout << -mincostflow(res,t,f) << endl;
	}


    // init();
	// int s = 0;
	// int t = 1;
	// add(0,1,2,1);
	// add(0,1,2,10);
	// int f = 3;
	// cout<<mincostflow(s, t, f)<<endl;
    return 0;
}
