// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	queue<string> que;
	for (int i=1; i<=n; i++){
		string name;
		cin >> name;
		que.push(name);
	}


	string s;
	cin >> s;
	vector<int> cnt(s.size(), 0);
	vector<int> id(s.size(), 0);
	int sc = 0;
	int mx = 0;
	int index = 0;
	for (int i=0; i<s.size(); i++){
		if (s[i] == 'W') {
			sc = 0;
			for (int j=i;j>=0;j--) {
				if(s[j] != 'W')break;
				sc++;
			}
			mx = max(mx,sc);
			index++;
			for (int j=i;j>=0;j--) {
				if(s[j] != 'W')break;
				id[j] = index;
				cnt[j] = sc;
			}
		}
		if (s[i] == 'B') {
			sc=0;
			for (int j=i;j>=0;j--) {
				if(s[j] != 'B')break;
				sc++;
			}
			mx = max(mx,sc);
			index++;
			for (int j=i;j>=0;j--) {
				if(s[j] != 'B')break;
				id[j] = index;
				cnt[j] = sc;
			}
		}
	}

	vector<pair<string,string>> ans;
	// map<pair<string,string>,bool> vis;
	string wo = que.front();
	string w1 = wo;
	que.pop();
	string bo = que.front();
	string b1 = bo;
	que.pop();
	string wd = que.front();
	string w2 = wd;
	que.pop();
	string bd = que.front();
	string b2 = bd;
	que.pop();

	set<int> app;
	for (int i=0; i<s.size(); i++){
		if (s[i] == 'W') {
			if(cnt[i] == mx) {
				if(app.count(id[i]) == 0) {
					app.insert(id[i]);
					ans.push_back(make_pair(w1,w2));
				}
			}
			//
			if (b1 == bd) {
				b1 = bo;
			}
			que.push(bd);
			bd = bo;
			bo = que.front();
			b2 = bo;
			que.pop();
			swap(wo,wd);
			//
		}
		else {
			if(cnt[i] == mx) {
				if(app.count(id[i]) == 0) {
					app.insert(id[i]);
					ans.push_back(make_pair(b1,b2));
				}
			}
			//
			if (w1 == wd) {
				w1 = wo;
			}
			que.push(wd);
			wd = wo;
			wo = que.front();
			w2 = wo;
			que.pop();
			swap(bo,bd);
			//
		}
	}
	for (int i=0; i<ans.size(); i++){
		// if(vis[make_pair(ans[i].first, ans[i].second)] == 0) {
		// 	vis[make_pair(ans[i].first,ans[i].second)] = 1;
		cout << ans[i].first << ' ' << ans[i].second << endl;
		// }
	}
	return 0;
}
