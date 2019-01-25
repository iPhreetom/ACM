// fyt
#include<bits/stdc++.h>
// #define int long long
// #define double long double
#define endl '\n'
using namespace std;

int n, k;
int a[105];
int b[105];
int dp[105][300005];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	for (int i=1; i<=n; i++){
		cin >> b[i];
		b[i] = a[i] - k*b[i];
	}



	// 二维背包
	// 用二维背包， 求出是否能够把这个背包装满
	// 但是不单调，不可行
	// 两个花费的范围都是 10000
	// 优化的 n^2 dp
	// for (int i=1; i<=n; i++){
	// 	for (int j=maxn; j>=a[i]; j--){
	// 		for(int k = maxn; k >= b[i]; k--) {
	// 			dp[j][k] = max(dp[j][k], dp[j-a[i]][k-b[i]]+w[i]);  // s[i][j] 刚好可以表示出这个物品的限制
	// 		}
	// 	}
	// }

	// 正解
	// 	我看过这种类型的题目，二维费用用得不熟练
	// 	（以后）应该把它试着转换成用得熟练的模型（拓展）
	// 	即把第二个属性转换为费用（代价）

	// mp[1][1000] = 0;
	// mp[0][1000] = 0;
	// mp[0][0] = 0;

	// for (int i=1; i<=100; i++){
	// 	vis[i][1000*i] = 1;
	// }
	//
	// vis[0][1000] = 1;
	// vis[0][0] = 1;
	// for (int i=1; i<=n; i++) {
	// 	for (int j=200000; j>=b[i]; j--) {
	// 		if(vis[i-1][j] != 0){
	// 			dp[i][j] = dp[i-1][j];
	// 			vis[i][j] = 1;
	// 		}
	// 		if(vis[i-1][j-b[i]] != 0) {
	// 			dp[i][j] = max(dp[i][j], dp[i-1][j-b[i]] + a[i]);
	// 			vis[i][j] = 1;
	// 		}
	// 	}
	// }
	//
	// if(dp[n][1000*n])cout<<dp[n][1000*n]<<endl;
	// else cout<<-1<<endl;

	// memset(dp,-0x3f,sizeof(dp));
	memset(dp,-0x3f,sizeof(dp));
	dp[0][100000] = 0;
	for (int i=1; i<=n; i++){
	    for (int j=200000; j>=0; j--) {
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-b[i]]+a[i]);
		}
	}

	if(dp[n][100000] <= 0){
		cout<<-1<<endl;
	}
	else{
		cout<<dp[n][100000]<<endl;
	}
	return 0;
}
