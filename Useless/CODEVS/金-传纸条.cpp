双线 棋盘dp
	用一次减法，或者带条件的加法，使得（非法）路径一定不是最优
#include<bits/stdc++.h>
using namespace std;

int mp[100][100];
int dp[100][100][100][100];

int maxx(int a,int b,int c,int d) {
	return max(max(a,b),max(c,d));
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> mp[i][j];
		}
	}


	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			for (size_t k = 1; k <= n; k++) {
				for (size_t l = 1; l <= m; l++) {
					dp[i][j][k][l] = maxx(
						dp[i-1][j][k-1][l],
						dp[i-1][j][k][l-1],
						dp[i][j-1][k-1][l],
						dp[i][j-1][k][l-1]);
					dp[i][j][k][l] += mp[i][j];
					if(i!=k || j!=l)dp[i][j][k][l] += mp[k][l];
				}
			}
		}
	}
	cout << dp[n][m][n][m] << endl;
	return 0;
}
