// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 998244353;
const int MOD = 998244353;
int dp[3005][3005];

// 组合数打表
const int MAXN = 3005;
int C[MAXN][MAXN];

void initC() {
    C[0][0] = 1;
    for (int i = 1; i < MAXN - 5; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tcase;
	initC();
	cin >> tcase;
	while(tcase--) {

		int n, m;
		cin >> n >> m;
		string s,t;

		for (int i=0; i<n+5; i++){
			for (int j=0; j<m+5; j++){
				dp[i][j] = 0;
			}
		}
		cin >> s >> t;

		for (int i=n-1; i>=0; i--){
			for (int j=0; j<m; j++){
				if (s[i] > t[m-j-1]) {
					if (j == 0) {
						dp[i][j] = 1 + dp[i+1][j];
						dp[i][j] %= mod;
					}
					else {
						dp[i][j] = C[n-i-1][j] + dp[i+1][j];
						dp[i][j] %= mod;
					}
				}
				else if(s[i] == t[m-j-1]) {
					dp[i][j] = dp[i+1][j-1] + dp[i+1][j];
					dp[i][j] %= mod;
				}
				else {
					dp[i][j] = dp[i+1][j];
				}
			}
		}

		int sum = dp[0][m-1];
		for (int i=m+1; i<=n; i++){
			if (s[n-i]!='0') {
				for (int j=m; j<i; j++){
					sum += C[i-1][j];
					sum %= mod;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
