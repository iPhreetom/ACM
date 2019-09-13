// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct node{
	int id;
	int x;
	int val;
	node(int id,int x,int val):id(id),x(x),val(val){}
	bool operator < (const node& b) const {
		return val < b.val;
	}
	bool operator > (const node& b) const {
		return val > b.val;
	}
};
vector<pair<int,int>> mp[51234];

void init(int n) {
	for (int i=1; i<=n; i++){
		mp[i].clear();
	}
}

int ans[51234];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n,m,q;
		cin >> n >> m >> q;
		init(n);
		while(m--){
			int u,v,w;
			cin >> u >> v >> w;
			mp[u].emplace_back(w,v);
		}
		vector<int> query;
		int mx = 0;
		while (q--) {
			int k; cin >> k;
			mx = max(mx,k);
			query.push_back(k);
		}
		for (int i=1; i<=n; i++){
			sort(mp[i].begin(),mp[i].end());
		}
		priority_queue<node,vector<node>,greater<node>> que;
		for (int i=1; i<=n; i++){
			if (!mp[i].empty()) {
				que.push(node(0,i,mp[i][0].first));
			}
		}
		int cnt = 1;
		while (!que.empty()) {
			node now = que.top();
			int val = now.val;
			int x = now.x;
			int id = now.id;
			que.pop();

			ans[cnt] = val;
			cnt++;
			if (cnt > mx) break;

			if (id+1 < mp[x].size()) {
				que.push(node(id+1,x,val-mp[x][id].first+mp[x][id+1].first));
			}
			int nt = mp[x][id].second;
			if (!mp[nt].empty()) {
				que.push(node(0,nt,val+mp[nt][0].first));
			}
		}
		for (int i=0; i<query.size(); i++){
			cout << ans[query[i]] << endl;
		}
	}
	return 0;
}
