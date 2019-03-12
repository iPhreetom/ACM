#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n, c;
	cin >> n >> c;

	vector<int> d(n+1, 0);
	vector<int> s(n+1, 0);
	vector<pair<int,pair<int,int>>> v(n+1, make_pair(0,make_pair(0,0)));
	vector<vector<int>> path(n+1, vector<int> (c+1, -1));
	vector<vector<int>> dp(n+1, vector<int> (c+1, 0));
	v[0] = make_pair(-2e9 ,make_pair(0,0));
	// cout << "v[0].first = " << v[0].first << endl;
	for (int i=1; i<=n; i++) {
		cin >> d[i] >> s[i];
		v[i] = make_pair(d[i]-s[i],make_pair(s[i],i));
	}

	sort(v.begin(),v.end());

	for (int i=1; i<=n; i++) {
		s[i] = v[i].second.first;
		d[i] = v[i].first + s[i];
	}

	for (int i=n; i>=1; i--) {
		for (int j=c; j>=s[i]; j--) {
				if(dp[i][j] < dp[i-1][j-s[i]]+1 && c-j >= d[i]-s[i]) {
				dp[i][j] = dp[i-1][j-s[i]]+1;
				path[i][j] = 1;
			}
		}
	}

	stack<int> que;
	int tp = c;
	for (int i=1; i<=n; i++) {
		if(path[i][tp] == 1) {
			tp -= s[i];
			que.push(v[i].second.second);
		}
	}
	cout << que.size() << endl;
	while(!que.empty()) {
		cout << que.top() << ' ';
		que.pop();
	}
	cout << endl;
	return 0;
}
