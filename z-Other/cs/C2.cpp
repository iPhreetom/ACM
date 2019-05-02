#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool vis[8];
vector<string> v;
int n;
int cs;

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	for (cs=1; cs<=t; cs++) {
		cin >> n;
		v.resize(n);
		for(auto &s:v)cin >> s;
		sort(v.begin(),v.end());
		int tmp = 0;
		while(next_permutation(v.begin(),v.end())){
			int ans = 0;
			map<string, bool> mp;
			memset(vis,0,sizeof(vis));
			for (int i=0; i<v.size(); i++) {
				if(vis[i])continue;
				for (int j=0; j<v.size(); j++) {
					if(i == j || vis[i] || vis[j] && v[i].back() == v[j].back())continue;
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
							mp[sf] = 1;
							vis[i] = 1;
							vis[j] = 1;
							ans += 2;
							break;
						}
						else {
							sf.pop_back();
						}
					}
				}
			}
			tmp = max(tmp,ans);
		}
		cout << "Case #" << cs << ": " << tmp << endl;
	}
	return 0;
}
