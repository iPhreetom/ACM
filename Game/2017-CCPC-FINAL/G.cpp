// 题解：
// 	碎碎念：
// 		比赛的时候没想出来，但是回头一看
// 		经典的前N个中，去M个的 动态规划
//
// 		如果总结题型，应该算是所谓的 区间覆盖 DP问题吧
// 		解法感觉很套路
// 	题解：（知识）
// 		有1-N个点，给予M段区间，只能够取K个
// 		问最多能够覆盖多少个点
// 		思路是：
// 			开一个right数组，保存每个点作为开头最远能够到达哪里
//
// 			用两重循环，顺着递推
// 				如果取了这个区间，那么区间终点的状态更新
// 				在这个状态之后的i+1 和 j+1，都可以无条件的转移过去，所以要【更新附近状态】


#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 2010;
int dp[maxn][maxn];
int rt[maxn];
int n,m,k;
int sum = 0;

int solve(){
	int ans = 0;
	for (int i=0; i<=n; i++){
		for(int j=0;j<=k;j++){
			dp[ rt[i+1] ][j+1] = max(dp[ rt[i+1] ][j+1] , dp[i][j] + rt[i+1]-i);
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
		}
	}
	return dp[n][k];
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	for(int nn=1;nn<=tt;nn++){
		memset(rt,0,sizeof(rt));
		memset(dp,0,sizeof(dp));

		cin>>n>>m>>k;
		for (int i=0; i<m; i++){
			int x,y;
			cin>>x>>y;
			for(int j=x;j<=y;j++){
				rt[j] = max(rt[j],y);
			}
		}
		sum = solve();
		cout<<"Case #"<<nn<<": "<<sum<<"\n";
	}
	return 0;
}
