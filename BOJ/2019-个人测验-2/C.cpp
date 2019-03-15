#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i=0; i<n; i++){
		cin >> s[i];
	}

	vector<int> in(27, 0);
	vector<vector<int>> mp(27, vector<int> (27, 0));
	for (int i=0; i<n-1; i++){
		for (int j=0; j<min(s[i].size(), s[i+1].size()); j++){
			bool ok = 0;
			if (s[i][j] != s[i+1][j]) {
				mp [s[i][j]-'a'] [s[i+1][j]-'a']++;
				in [ s[i+1][j]-'a' ] ++ ;
				ok = 1;
				break;
			}
			if (!ok) {
				if (s[i].size() > s[i+1].size()) {
					cout << "Impossible" << endl;
					return 0;
				}
			}
		}
	}

	queue<int> que;
	queue<char> ans;
	for (int i=0; i<26; i++){
		if (in[i] == 0) {
			que.push(i);
		}
	}

	// vector<bool> vis(26, 0);
	while (!que.empty()) {
		int t = que.front();
		ans.push(t+'a');
		que.pop();

		for (int i=0; i<27; i++){
		    if (i != t && mp[t][i] >= 1) {
				in[i]-=mp[t][i];
				if(in[i] == 0)que.push(i);
			}
		}
	}

	if (ans.size() < 26)cout << "Impossible";
	else while(!ans.empty())cout << ans.front(),ans.pop();
	cout << endl;
	return 0;
}
