#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int mx = -1e8;
		int tp;
		int ans = -1e8;
		for (int i=1; i<=n; i++) {
			cin >> tp;
			ans = max(ans, mx-tp);
			mx = max(tp,mx);
		}
		cout << ans << endl;
		// cout << "ans = " << ans << endl;
	}
	return 0;
}
