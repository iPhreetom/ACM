// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n,m;
int ans = 1e18;
int dp[100000];
void dfs(int now, int cnt) {
	if (dp[now] <= cnt) {
		return ;
	}
	dp[now] = cnt;
	if (now > 1) dfs(now-1,cnt+1);
	if (now < 1e4) dfs(now*2,cnt+1);
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	memset(dp,0x3f,sizeof(dp));
	dfs(n, 1);
	cout << dp[m]-1 << endl;
	return 0;
}
