#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int pos[31234];
int dp[31234][612];
bool vis[31234][612];
int lower;
int upper;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, d;
	cin >> n >> d;

	for (int i=1; i<=n; i++) {
		int p; cin >> p;
		pos[p]++;
	}

	lower = 10;
	upper = 600;

	vis[d][300] = 1;
	dp[d][300] = pos[d];
	int ans = pos[d];

	// cout << "lower = " << lower << endl;
	// cout << "upper = " << upper << endl;
	for (int i=d+1; i<=30000; i++) {
		for (int j=lower; j<=upper; j++) {
			int real_dis = d + (j-300);
			if(real_dis <= 0)continue;
			if(i<=real_dis)break;
			// 0 and get it
			if(vis[i-real_dis][j]) dp[i][j] = max(dp[i][j],dp[i-real_dis][j]),vis[i][j] = 1;

			// -1 and get it
			if(vis[i-real_dis][j+1]) dp[i][j] = max(dp[i][j],dp[i-real_dis][j+1]),vis[i][j] = 1;

			// +1 and get it
			if(vis[i-real_dis][j-1]) dp[i][j] = max(dp[i][j],dp[i-real_dis][j-1]),vis[i][j] = 1;
			if(vis[i][j] && pos[i])dp[i][j]+=pos[i];
			ans = max(ans,dp[i][j]);

			// if(vis[i][j]){
			// 	cout << "dp[i][j] = " << dp[i][j] << endl;
			// 	cout << "vis[i][j] = " << vis[i][j] << endl;
			// 	cout << "real_dis = " << real_dis << endl;
			// 	cout << "i = " << i << endl;
			// 	cout << "j = " << j << endl;
			// }
		}
	}

	cout << ans << endl;


	return 0;
}
