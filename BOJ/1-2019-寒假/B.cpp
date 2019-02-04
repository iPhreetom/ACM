// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9+7;
long long dp[5005][5005];
long long prefix[5005];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	int n;
	cin >> n;
	for (int i=1; i<=n; i++){
		char c;
		cin>>c;
		s.push_back(c);
	}

	int cnt = 1;
	bool eat = 0;
	dp[0][1] = 1;

	for (int i=1; i<=n; i++){
		if(eat) {
			for (int j=1; j<=cnt; j++){
				dp[i][j] = dp[i-1][j];
			}

			if(s[i-1] != 'f') {
				eat = 0;
			}
			else {
				cnt++;
				for (int j=cnt; j>=1; j--){
					dp[i][j] = dp[i][j-1];
				}
			}
			continue;
		}

		prefix[1] = dp[i-1][1];
		for (int j=2; j<=cnt; j++){
			prefix[j] = prefix[j-1] + dp[i-1][j];
		}

		for (int j=1; j<=cnt; j++){
			dp[i][j] = (prefix[cnt] - prefix[j-1])%mod;
		}

		if(s[i-1] == 'f') {
			eat = 1;
			cnt++;
			for (int j=cnt; j>=1; j--){
				dp[i][j] = dp[i][j-1];
			}
		}
	}


	long long ans = 0;
    for (int j=1; j<=cnt; j++){
		ans += dp[n][j];
		ans %= mod;
    }

	cout<<ans<<endl;
	return 0;
}
