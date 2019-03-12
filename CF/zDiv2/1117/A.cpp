#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	int mx = 0;
	int ans = 0;

	vector<int> v(212345, 0);
	for (int i=1; i<=n; i++) {
	    cin >> v[i];
		mx = max(mx, v[i]);
	}

	int cnt = 0;
	for (int i=1; i<=n; i++) {
		if(v[i] == mx) {
			cnt ++;
		}
		else {
			ans = max(cnt, ans);
			cnt = 0;
		}
	}
	ans = max(ans, cnt);

	cout << ans << endl;
	return 0;
}
