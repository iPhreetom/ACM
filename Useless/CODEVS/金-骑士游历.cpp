简单棋盘dp
	注意要点：dp[sx][sy]=1;可能因为不正确的转移姿势，被覆盖
	需要在循环内，加上这么一句，或者跳过开头的转移，
		或者把初值赋值放在第一次转移
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int dp[100][100];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1++;
	x2++;
	y1++;
	y2++;
	m++;
	n++;
	dp[x1][y1] = 1;
	for (int i=2; i<=n; i++) {
		for (int j=2; j<=m; j++) {
			dp[i][j] = dp[i-2][j-1]+dp[i-2][j+1]+dp[i-1][j+2]+dp[i-1][j-2];
			if(i == x1 && j == y1)dp[i][j] = 1;
		}
	}
	cout << dp[x2][y2] << endl;
	return 0;
}
