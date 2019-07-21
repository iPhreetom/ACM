// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n,k;
		cin >> n >> k;
		vector<vector<int>> v;
		vector<int> ans(n);
		int len = 0;
		for (int i=0; i<n; i++){
			int l,r;
			cin >> l >> r;
			r--;
			v.push_back({l,r,i});
		}
		sort(v.begin(),v.end());
		set<pair<int,int>> st;
		int cnt = 0;
		for (int i=0; i<n; i++){
			if (st.empty()) {
				st.insert({v[i][1],++cnt});
				ans[v[i][2]] = cnt;
			}
			else {
				if (st.size() == k) {
					st.insert({v[i][1],st.begin()->second});
					ans[v[i][2]] = st.begin()->second;
					st.erase(st.begin());
				}
				else {
					st.insert({v[i][1],++cnt});
					ans[v[i][2]] = cnt;
				}
			}
			if (cnt == k) cnt = 0;
		}

		cout << len << '\n';
		for (int i=0; i<n; i++){
			if (i == 0) cout << ans[i];
			else cout << ' ' << ans[i];
		}
		cout << '\n';
	}
	return 0;
}
