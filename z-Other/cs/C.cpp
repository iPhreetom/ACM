#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool vis[2000];
vector<string> v;
int n;
int cs;

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	for (cs=1; cs<=t; cs++) {
		int ans = 0;
		map<string, bool> mp;
		memset(vis,0,sizeof(vis));

		cin >> n;
		v.resize(n);
		for(auto &s:v)cin >> s;
		for (int i=0; i<v.size(); i++) {
			if(vis[i])continue;
			vector<string> lis;
			vector<int> lis2;
			int mx = 0;
			for (int j=0; j<v.size(); j++) {
				if(i == j || vis[j] || v[i].back() != v[j].back())continue;
				string a = v[i];
				string b = v[j];
				string sf;
				while(!a.empty() && !b.empty()) {
					if(a.back() == b.back()) {
						sf.push_back(b.back());
						a.pop_back();
						b.pop_back();
					}
					else break;
				}
				while(!sf.empty()){
					if(mp[sf] == 0) {
						lis.push_back(sf);
						lis2.push_back(j);
						mx = max(mx,(int)lis.back().size());
						break;
					}
					else {
						sf.pop_back();
					}
				}
			}
			// cout << "mx = " << mx << endl;
			for (int j=0; j<lis.size(); j++) {
				if(lis[j].size() == mx) {
					mp[lis[j]] = 1;
					vis[i] = 1;
					vis[lis2[j]] = 1;
					ans += 2;
					break;
				}
			}
		}
		cout << "Case #" << cs << ": " << ans << endl;
	}
	return 0;
}
