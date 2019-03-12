#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int ans = 0;
	for (int i=0; i<=n; i++) {
		// i ge A -> 2*i ge B
		if(2*i > m) break;
		int tp = i;
		tp = m-2*i;
		// cout << "tp = " << tp << endl;
		ans = max(ans, i + min(tp, (n-i)/2 ));
	}
	cout << ans << endl;
	return 0;
}
