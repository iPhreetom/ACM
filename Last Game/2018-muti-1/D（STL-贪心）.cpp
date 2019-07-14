#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		set<int> s;
		for (int i=1; i<=n; i++) {
			s.insert(i);
		}
		vector<int> ans;
		vector<int> beginp(n+1,0);
		vector<int> near(n+1,0);
		vector<int> endp(n+1,0);
		vector<pair<int,int>> fact;
		for (int i=1; i<=m; i++) {
			int l, r;
			cin >> l >> r;
			fact.push_back(make_pair(l,r));
		}
		sort(fact.begin(),fact.end());

		int mx = 0;
		for (int i=0; i<fact.size(); i++) {
			int l = fact[i].first;
			int r = fact[i].second;
			if (r > mx) {
				endp[beginp[l]] = 0;
				beginp[l] = r;
				mx = r;
				endp[r] = l;
			}
		}
		int nt = n+1;
		for (int i=n; i>=1; i--) {
			near[i] = nt;
			if (beginp[i] != 0) nt = i;
		}
		int cnt = 0;
		for (int i=1; i<=n; i++) {
			if (beginp[i] != 0) cnt++;
			if (cnt == 0) ans.push_back(1);
			else {
				ans.push_back(*s.begin());
				s.erase(s.begin());
				if (endp[i] != 0) {
					for (int j=endp[i]; j<=min(near[endp[i]]-1,i); j++) {
						s.insert(ans[j-1]);
					}
				}
			}
			if (endp[i] != 0) cnt--;
		}
		for (int i=0; i<ans.size(); i++) {
			if (i != 0) cout << ' ';
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
