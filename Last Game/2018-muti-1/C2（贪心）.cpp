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
		cin >> n;
		vector<pair<int,pair<int,int>>> ans;
		for (int i=1; i<=3*n; i++) {
			int x,y;
			cin >> x >> y;
			ans.push_back(make_pair(x,make_pair(y,i)));
		}
		sort(ans.begin(),ans.end());
		for (int i=0; i<ans.size(); i+=3) {
			cout << ans[i].second.second << ' ';
			cout << ans[i+1].second.second << ' ';
			cout << ans[i+2].second.second << endl;
		}
	}
	return 0;
}
