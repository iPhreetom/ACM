标准棋盘dp（二维图论dp）
	通过上下左右的转移，得到一个从左上到右下的最优解
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int dp[134][134];
int mp[134][134];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int x,y;
	int cx,cy;
	cin >> x >> y >> cx >> cy;
	x++;
	y++;
	cx++;
	cy++;
	dp[1][1] = 1;

	mp[cx][cy] = 1;
	mp[cx+2][cy+1] = 1;
	if (cx >= 2) mp[cx-2][cy+1] = 1;
	if (cy >= 1) mp[cx+2][cy-1] = 1;
	if (cx >= 2 && cy >= 1) mp[cx-2][cy-1] = 1;
	mp[cx+1][cy+2] = 1;
	if (cx >= 1) mp[cx-1][cy+2] = 1;
	if (cy >= 2) mp[cx+1][cy-2] = 1;
	if (cx >= 1 && cy >= 2) mp[cx-1][cy-2] = 1;

	for (int i=1; i<=x; i++) {
		for (int j=1; j<=y; j++) {
			if(mp[i][j] == 0)dp[i][j] = dp[i-1][j] + dp[i][j-1];
			if(i == 1 && j == 1)dp[i][j] = 1;
		}
	}
	cout << dp[x][y] << endl;

	return 0;
}
