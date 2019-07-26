#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int a[212];
int dp[212][212];
int w[212][212];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	memset(dp,0x3f,sizeof(dp));
	for (int i=1; i<=n; i++) {
	    cin >> a[i];
		dp[i][i] = 0;
	}
	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			w[i][j] = w[i][j-1] + a[j];
		}
	}

	for (int len = 1; len <= n; len++) {
		int ed = n-len+1;
		for (int be = 1; be <= ed; be++) {
			int sg = be+len-1;
			for (int p=be; p<sg; p++) {
				dp[be][sg] = min(dp[be][sg],dp[be][p]+dp[p+1][sg]+w[be][sg]);
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}
