// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 2123;
int d1[maxn];
bool vis[maxn];
typedef pair<int,int> pii;
vector<pair<int,int> > mp[maxn];


inline void init(){
	memset(d1,0x3f,sizeof(d1));
	memset(vis,0,sizeof(vis));
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

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, e, s, k, c;
		cin >> n >> e >> s >> k >> c;
		for (int i=0; i<=n; i++){
			mp[i].clear();
		}

		vector<int> lis;
		for (int i=0; i<k; i++){
			int t; cin >> t;
			lis.push_back(t);
		}

		for (int i=0; i<e; i++){
			int u, v, w;
			cin >> u >> v >> w;
			mp[u].push_back(make_pair(v,w));
			mp[v].push_back(make_pair(u,w));
		}

		init();
		dijkstra(s);
		int mxhero = 0;
		for (int i=1; i<=n; i++){
			mxhero = max(mxhero, d1[i]);
		}

		init();
		priority_queue<pii,vector<pii>,greater<pii> > que;// 从小到大
		for (int i=0; i<k; i++){
			int t = lis[i];
			d1[t] = 0;
			que.push(make_pair(0,t));
		}
		// min length
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
		int mxteam = 0;
		for (int i=1; i<=n; i++){
			mxteam = max(mxteam, d1[i]);
		}
		int ans = 0;
		if (mxhero <= c*mxteam) {
			ans = mxhero;
		}
		else {
			ans = mxteam;
		}
		cout << ans << endl;
	}
	return 0;
}
