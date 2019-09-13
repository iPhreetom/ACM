// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int dp[112345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	for (int i=0; i<=3; i++){
	    dp[i] = 1;
	}
	for (int i=4; i<112345; i++){
		dp[i] = dp[i-3]+dp[i-1];
		dp[i] %= 998244353;
	}

	while(T--){
		int n,x,y;
		cin >> n >> x >> y;
		if (x > y)swap(x,y);
		if (abs(x-y)==1 && min(x,y)!=1 && max(x,y)!=n) {
			cout << 0 << endl;
		}
		else {
			if (x == 1 && y == n) {
				cout << dp[y] << endl;
			}
			else {
				if (x == 1) {
					cout << dp[y-1] << endl;
				}
				else if(y == n){
					cout << dp[y-x] << endl;
				}
				else cout << dp[y-x-1] << endl;
			}
		}
		// cout<<"dp[y-x] = "<<dp[y-x]<<endl;
		// cout<<"dp[y-x+1] = "<<dp[y-x+1]<<endl;
		// cout<<"dp[y-x-1] = "<<dp[y-x-1]<<endl;
		// cout<<"dp[y-x+2] = "<<dp[y-x+2]<<endl;
		// cout<<"dp[y-x-2] = "<<dp[y-x-2]<<endl;
	}
	// for (int i=1; i<112345; i++){
	// 	if (dp[i] == 253604680) {
	// 		cout << i << endl;
	// 	}
	// }
	return 0;
}
