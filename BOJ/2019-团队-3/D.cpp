// fyt
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

map<string,vector<pair<string,int>>> mp;
map<string,int> d;
map<string,bool> vis;
typedef pair<int,string> pii;

inline void dijkstra(string s){
	priority_queue<pii,vector<pii>,greater<pii> > que;// 从小到大
	// fill(d1,d1+n+1,inf);
	d[s] = 0;
	que.push( make_pair(0,s) );
	while(!que.empty()){
		pii p = que.top();
		que.pop();

		string &from = p.second;
		if(vis[from])continue;
		vis[from]=1;

		// if(d1[from] < p.first)continue;// 此时这个节点被更新了更小的值，舍弃曾经的最小值

		for(int i=0;i<mp[from].size();i++){
			string &to = mp[from][i].first;
			int &c = mp[from][i].second;
			if(d[to] > d[from] + c){
				d[to] = d[from] + c;
				que.push(make_pair(d[to],to));
			}
		}
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;

	const int inf = 1e15;
	vector<string> ans(n);
	for (int i=0; i<n; i++){
		cin >> ans[i];
		vis[ans[i]] = 0;
		if(ans[i] != "English")	d[ans[i]] = inf;
	}

	for (int i=0; i<m; i++){
		string u,v;
		int c;
		cin >> u >> v >> c;
		mp[v].push_back(make_pair(u,c));
		mp[u].push_back(make_pair(v,c));
	}

	dijkstra("English");
	int sum = 0;
	for(auto& i : d) {
		if (i.second == inf) {
			cout << "Impossible" << endl;
			return 0;
		}
		cout<<"i.first = "<<i.first<<endl;
		cout<<"i.second = "<<i.second<<endl;
		sum += i.second;
	}
	cout << sum << endl;

	return 0;
}
