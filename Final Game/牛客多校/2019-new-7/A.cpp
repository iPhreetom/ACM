// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		vector<string> ans;
		while(!s.empty()){
			string tmp = s.substr(0,1);
			bool can = 1;
			for (int i=1; i<s.size(); i++) {
				tmp.push_back(s[i]);
				string tmp2 = tmp+tmp;
				for (int j=1; j<tmp.size(); j++){
					if (tmp > tmp2.substr(j,tmp.size())) {
						can = 0;
						break;
					}
				}
				if (!can) break;
			}
			if (!can) tmp.pop_back();
			s.erase(0,tmp.size());
			ans.push_back(tmp);
		}

		vector<int> vis(ans.size());
		for (int i=0; i<ans.size(); i++){
		    vis[i] = i;
		}
		while(true) {
			bool change = 0;
			for (int i=1; i<ans.size(); i++){
				if (vis[i] == i) {
					string tmp;
					int index = 0;
					for (int j=i-1; j>=0 ;j--) {
						if (vis[j] == j) {
							index = j;
							break;
						}
					}
					int index2 = (int)ans.size()-1;
					for (int j=i+1; j<ans.size(); j++) {
						if (vis[j]==j) {
							index2 = j-1;
							break;
						}
					}
					for (int j=index; j<=index2; j++){
						tmp += ans[j];
					}
					bool can = 1;
					string tmp2 = tmp+tmp;
					for (int j=1; j<tmp.size(); j++) {
						if (tmp > tmp2.substr(j,tmp.size())) {
							can = 0;
							break;
						}
					}
					if (can) vis[i] = i-1, change = 1;
				}
			}
			if (!change) break;
		}
		for (int i=0; i<ans.size(); i++){
			if (i == 0) {cout << ans[i]; continue;}
			if (vis[i]==i) cout << ' ' << ans[i];
			else cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
