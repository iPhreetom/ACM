#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	priority_queue<int> que;
	for (int i=1; i<=n; i++) {
		int t; cin >> t;
		que.push(t);
	}

	int mx = que.top();
	que.pop();
	int res = que.top();

	int one = mx*k + res;

	int can = m/(k+1);
	int ans = can*one;
	ans += (m - m/(k+1)*(k+1))*mx;
	cout << ans << endl;
	return 0;
}
