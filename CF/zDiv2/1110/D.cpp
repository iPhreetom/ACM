#include<bits/stdc++.h>
using namespace std;

int a[1123456];
int dp[1123456][3][3][3];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;

	for (int i=1; i<=n; i++){
		int t;cin >>t;
		a[t] ++;
	}
	memset(dp,-1,sizeof(dp));

	dp[0][0][0][0] = 0;
	for (int i=1; i<=m+1; i++){
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				for (int z = 0; z < 3 && z <= (a[i]-x-y); z++) {
					for (int t = 0; t < 3; t++) {
						if(dp[i-1][t][x][y] < 0)continue;
						// cout<<"x = "<<x<<endl;
						// cout<<"y = "<<y<<endl;
						// cout<<"z = "<<z<<endl;
						// cout<<"t = "<<t<<endl;
						dp[i][x][y][z] = max(
							dp[i][x][y][z],
							(dp[i-1][t][x][y] + (a[i]-x-y-z)/3 + z)
						);
						// cout<<"dp[i][x][y][z] = "<<dp[i][x][y][z]<<endl;
					}
				}
			}
		}
	}
	cout << dp[m+1][0][0][0] << endl;


	return 0;
}
