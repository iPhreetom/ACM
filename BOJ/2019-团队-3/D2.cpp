// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;

	const int inf = 1e15;
	vector<string> ans(n);
	// map<string,int> d;
	map<string,bool> vis;
	map<string,vector<pair<string,int>>> mp;

	for (int i=0; i<n; i++){
		cin >> ans[i];
		if(ans[i] != "English")	vis[ans[i]] = 0;
	}

	for (int i=0; i<m; i++){
		string u,v;
		int c;
		cin >> u >> v >> c;
		mp[v].push_back(make_pair(u,c));
		mp[u].push_back(make_pair(v,c));
	}

	int sum = 0;
	queue<string> que1;
	queue<string> que2;
	bool ft = 1;

	que1.push("English");
	vis["English"] = 1;
	while(!que1.empty() || !que2.empty()) {
		if(ft) {
			map<string,int> tmp;
			while(!que1.empty()) {
				string &s = que1.front();
				for (int i=0; i<mp[s].size(); i++){
					string &v = mp[s][i].first;
					int c = mp[s][i].second;
					if(!vis[v]) {
						if(tmp[v] == 0) {
							tmp[v] = c;
						}
						else {
							tmp[v] = min(tmp[v],c);
						}
					}
				}
				que1.pop();
			}
			for(auto &i : tmp) {
				vis[i.first] = 1;
				que2.push(i.first);
				sum += i.second;
			}
		}
		else {
			map<string,int> tmp;
			while(!que2.empty()) {
				string &s = que2.front();
				for (int i=0; i<mp[s].size(); i++){
					string &v = mp[s][i].first;
					int c = mp[s][i].second;
					if(!vis[v]) {
						if(tmp[v] == 0) {
							tmp[v] = c;
						}
						else {
							tmp[v] = min(tmp[v],c);
						}
					}
				}
				que2.pop();
			}
			for(auto &i : tmp) {
				vis[i.first] = 1;
				que1.push(i.first);
				sum += i.second;
			}
		}
		ft = !ft;
	}
	for (int i=0; i<ans.size(); i++){
		if(!vis[ans[i]]){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << sum << endl;
	return 0;
}
