// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int dp[3123][3123];
int n,m;
const int mod = 1e9+7;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin >> n >> m) {
		dp[0][0] = 1;
		if (n < m) swap(n,m);
		for (int i=0; i<=n; i++) {
			for (int j=0; j<=m+i; j++) {
				if (i == 0 && j == 0) continue;
				dp[i][j] = ( (i==0?0:dp[i-1][j]) + (j==0?0:dp[i][j-1]) )%mod;
			}
		}
		for (int i=n+1; i<=n+m; i++) {
			for (int j=i-n; j<=m+n; j++) {
				if (i == 0 && j == 0) continue;
				dp[i][j] = ( (i==0?0:dp[i-1][j]) + (j==0?0:dp[i][j-1]) )%mod;
			}
		}
		cout << dp[n+m][n+m] << endl;
		for (int i=0; i<=n+m+5; i++){
			for (int j=0; j<=n+m+5; j++){
				dp[i][j] = 0;
			}
		}
	}

	return 0;
}
