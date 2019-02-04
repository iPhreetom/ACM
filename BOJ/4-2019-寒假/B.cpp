#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int dp[112][112][112];
bool vis[112][112][112];

void dfs(int s, int j, int b) {

	if(s-1 >= 0){
		dp[s-1][j][b] += dp[s][j][b];
		if(vis[s-1][j][b] == 0){
			vis[s-1][j][b] = 1;
			dfs(s-1, j, b);
		}
	}
	if(j-1 >= 0){
		dp[s][j-1][b] += dp[s][j][b];
		if(vis[s][j-1][b] == 0){
			vis[s][j-1][b] = 1;
			dfs(s, j-1, b);
		}
	}
	if(b-1 >= 0){
		dp[s][j][b-1] += dp[s][j][b];
		if(vis[s][j][b-1] == 0){
			vis[s][j][b-1] = 1;
			dfs(s, j, b-1);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int s, jj, b;
	cin >> s >> jj >> b;

	vis[s][jj][b] = 1;
	dp[s][jj][b] = 1;
	dfs(s, jj, b);

	int sum = 0;
	vector<int> cnt(4,0);

	for (int i=1; i<=s; i++){
		cnt[1] += dp[i][0][0];
	}
	for (int i=1; i<=jj; i++){
	    cnt[2] += dp[0][i][0];
	}
	for (int i=1; i<=b; i++){
	    cnt[3] += dp[0][0][i];
	}

	for (int i=1; i<=3; i++){
	    sum += cnt[i];
		cout<<"cnt[i] = "<<cnt[i]<<endl;
	}
	return 0;
}


// for (int i=1; i<=jj; i++){
// 		for (int j=1; j<=b; j++){
// 				sum += dp[0][i][j];
// 				cnt[1] += dp[0][i][j];
// 			}
// 		}
// 		for (int i=1; i<=s; i++){
// 				for (int j=1; j<=b; j++){
// 						sum += dp[i][0][j];
// 						cnt[2] += dp[i][0][j];
// 					}
// 				}
// 				for (int i=1; i<=s; i++){
// 						for (int j=1; j<=jj; j++){
// 								sum += dp[i][j][0];
// 								cnt[3] += dp[i][j][0];
// 							}
// 						}
