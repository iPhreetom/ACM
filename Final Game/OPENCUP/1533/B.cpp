// fyt
#include<bits/stdc++.h>
#include<unordered_map>
#define endl '\n'
using namespace std;

unordered_map<int,int> mp;
bool vis[5123][5123];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	vector<int> v;
	for (int i=1; i<=n; i++){
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());

	for (int i=0; i<v.size(); i++){
		mp[v[i]] = i+1;
	}

	int ans = 2;
	for (int i=0; i<v.size()-1; i++) {
		for (int j=i+1; j<v.size(); j++) {
			if (!vis[i][j]) {
				vis[i][j] = 1;
				int dif = v[j] - v[i];
				int now = v[j];
				int cnt = 2;
				int last = j;
				while (mp.count(now+dif) != 0) {
					cnt++;
					now += dif;
					int index = mp[now]-1;
					vis[last][index] = 1;
					last = index;
				}
				ans = max(ans,cnt);
			}
		}
	}

	cout << ans << endl;
	return 0;
}
