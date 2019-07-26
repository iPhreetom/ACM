#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int lt[212];
int rt[212];
int dp[212][212];
int w[212][212];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	// memset(dp,0x3f,sizeof(dp));
	for (int i=1; i<=n; i++) {
		cin >> lt[i];
		lt[n+i] = lt[i];
	}
	for (int i=1; i<=n*2-1; i++) {
		rt[i] = lt[i+1];
		dp[i][i] = 0;
	}

	for (int len=2; len<=n; len++) {
		int ed = 2*n - len;
		for (int be=1; be<=ed; be++) {
			int sg = be + len - 1;
			for (int p = be; p<sg; p++) {
				dp[be][sg] = max(dp[be][sg],
					dp[be][p]+dp[p+1][sg]+ (lt[be]*lt[p+1]*lt[sg+1]) );
					// 转移方式，记得+1，记得转移代价
			}
		}
	}

	int mn = 0;
	for (int i=1; i<=n; i++) {
		mn = max(mn, dp[i][i+n-1]);
	}
	cout << mn << endl;
	return 0;
}

// 30 + 100 + 400
