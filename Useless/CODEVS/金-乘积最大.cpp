#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int string_to_int(string &s) {
	int ret = 0;
	int cnt = 1;
	for (int i=(int)s.size()-1; i>=0; i--) {
		ret += (s[i]-'0')*cnt;
		cnt*=10;
	}
	return ret;
}

int dp[50][50];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = "#" + s;

	for (int pre=1; pre<=n; pre++) {
		for (int kp=1; pk<=min(pre,k); pk++) {

		}
	}
	return 0;
}
