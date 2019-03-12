#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,v;
	cin >> n >> v;
	int c = 0;
	int ans = 0;
	for (int i=1; i<=n; i++) {
		if(c < n-i) {
			ans += min(v-c,n-i-c)*i;
			c += min(v-c,n-i-c);
		}
		c--;
	}
	cout << ans << endl;
	return 0;
}
