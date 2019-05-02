#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int dp[112345][27];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	int q;
	const int maxn = 1e18;
	cin >> s;
	cin >> q;

	s = "#" + s;
	for (int j=0; j<26; j++) {
		dp[s.size()][j] = maxn;
	}
	for (int i=(int)s.size()-1; i>=0; i--) {
		for (int j=0; j<26; j++) {
			dp[i][j] = dp[i+1][j];
		}
		dp[i][s[i+1]-'a'] = i+1;
	}

	while (q--) {
		string t;
		int index = 0;
		cin >> t;

		bool findit = 1;
		for (int i=0; i<t.size(); i++) {
			if(dp[index][t[i]-'a'] == maxn){
				findit = 0;
				cout << "NO" << endl;
				break;
			}
			else {
				index = dp[index][t[i]-'a'];
			}
		}
		if(findit){
			cout << "YES" << endl;
		}
	}
	return 0;
}
