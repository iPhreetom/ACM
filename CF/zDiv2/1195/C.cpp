// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int dp[112345][3];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> v1(n+1);
	vector<int> v2(n+1);
	for (int i=1; i<=n; i++){
		cin >> v1[i];
	}
	for (int i=1; i<=n; i++){
		cin >> v2[i];
	}
	for (int i=1; i<=n; i++){
		dp[i][0] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
		dp[i][1] = max({dp[i-1][0],dp[i-1][2]})+v1[i];
		dp[i][2] = max({dp[i-1][0],dp[i-1][1]})+v2[i];
	}
	cout << max({dp[n][0],dp[n][1],dp[n][2]}) << endl;
	return 0;
}
