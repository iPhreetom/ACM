// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int lis[1123456][27];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;

	n = s.size();
	m = t.size();
	for (int j=0; j<27; j++){
		lis[n][j] = -1;
	}
	for (int i=n-1; i>=0; i--) {
		for (int j=0; j<27; j++) {
			lis[i][j] = lis[i+1][j];
		}
		lis[i][s[i]-'a'] = i;
		for (int j=0; j<=s[i]-'a'; j++) {
			lis[i][j] = lis[i][s[i]-'a'];
		}
	}

	int index = 0;
	int ans = -1;
	if (lis[0][t[index]-'a'+1] != -1) {
		ans = n - lis[0][t[index]-'a'+1];
	}
	for (int i=0; i<s.size(); i++) {
		if (index == m) {
			ans = max(ans, m+n-i);
			break;
		}
		if (s[i] == t[index]) {
			index++;
			if (index != m) {
				if (lis[i+1][t[index]-'a'+1] != -1) {
					ans = max(ans, index + n-lis[i+1][t[index]-'a'+1]);
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
// 3 3
// bba
// bba
