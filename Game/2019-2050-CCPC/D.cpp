#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		// vector<int> v(n);
		vector<vector<int> > mp(m+1);
		for (int i=0; i<n; i++) {
			int tp;
			cin >> tp;
			mp[tp].push_back(i+1);
		}
		int ans = 0;
		int ps = n/2;
		for (int i=1; i<=m; i++) {
			int num = mp[i].size()/k;
			for (int j=0; j<num; j++) {
				if(mp[i][j] <= ps) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
