#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int n;
vector<int> a(212345, 0);
int sum = 0;

// void solve(int l,int r) {
// 	if(l == r) {
// 		sum++;
// 		return;
// 	}
//
// 	int index = l;
// 	while(index <= r && a[index] == a[l])index++;
// 	if(index > r)return ;
//
// 	bool findit = 0;
// 	for (int i=index; i<=r; i++) {
// 		if (a[i] == a[l]) {
//
// 		}
// 	}
// }

int dp[5005][5005];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++) {
	    cin >> a[i];
	}
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}

	// for (int i=1; i<=5000; i++) {
	// 	if(i != a[1])dp[1][i] = 1;
	// }
	//
	// for (int i=2; i<=n; i++) {
	// 	for (int j=1; j<=5000; j++) {
	// 		if(a[i] == a[i-1]){
	// 			dp[i][j] = dp[i-1][j];
	// 			continue;
	// 		}
	// 		if(a[i] != j)dp[i][j] = dp[i-1][j]+1;
	// 		else dp[i][j] = dp[i-1][j];
	// 	}
	// }

	for (int i=2; i<=n; i++) {
		for (int j=1; j<=i-1; j++) {
			dp[1][j] = min(dp[1][j], dp[1][j]+dp[j+1][i])
		}
	}

	int mn = 1e18;
	for (int i=1; i<=5000; i++) {
	    mn = min(mn,dp[n][i]);
	}

	cout << mn << endl;
	return 0;
}
