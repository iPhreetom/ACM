#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int dp[1123][1123];
int a[1123];
int b[1123];
int c[1123];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,C;
		cin >> n >> C;
		memset(dp,0,sizeof(dp));
		for (int i=1; i<=n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		for (int i=0; i<=n; i++) {
			dp[i][0] = C;
		}
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=i; j++) {
				if(dp[i-1][j-1] > 0) {
					// 前面j-1是合法的
					if(dp[i-1][j] > 0) {
						// 前面这一位是合法的
						if (min(dp[i-1][j-1],b[i]) > a[i]) {
							dp[i][j] = max(dp[i-1][j]+c[i], min(dp[i-1][j-1],b[i])-a[i]+c[i]);
						}
						else {
							dp[i][j] = dp[i-1][j] + c[i];
						}
					}
					else {
						// 前一位直接转移是不合法的
						if (min(dp[i-1][j-1],b[i]) > a[i]) {
							dp[i][j] = min(dp[i-1][j-1],b[i])-a[i]+c[i];
						}
					}
				}
				else {
					// 不取这一位
					if(dp[i-1][j] > 0) {
						// 前面合法
						dp[i][j] = dp[i-1][j] + c[i];
					}
					// 不合法不转移
				}
			}
		}
		for (int i=n; i>=0; i--) {
			if(dp[n][i] > 0) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
