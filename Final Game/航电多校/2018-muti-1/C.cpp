#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	const int inf = 1e9+7;
	cin >> t;
	while(t--){
		int n;
		map<int,pair<pair<int,int>,pair<int,int>>> mp;
		cin >> n;
		for (int i=1; i<=3*n; i++) {
			int x,y;
			cin >> x >> y;
			if (mp.find(x) != mp.end()) {
				mp[x].second = make_pair(y,i);
				if (mp[x].first.first > y) {
					swap(mp[x].first,mp[x].second);
				}
			}
			else {
				mp[x] = make_pair(make_pair(y,i),make_pair(inf,0));
			}
		}
		vector<int> ans;
		for (auto i:mp) {
			int n1 = i.second.first.second;
			int n2 = i.second.second.second;
			int y2 = i.second.second.first;
			ans.push_back(n1);
			if (y2 != inf) ans.push_back(n2);
		}
		int cnt = 0;
		for (int i=0; i<ans.size(); i+=3) {
			cout << ans[i] << ' ' << ans[i+1] << ' ' << ans[i+2] << endl;
		}
	}
	return 0;
}
