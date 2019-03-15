// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s,t;
	cin >> s >> t;

	string ans = s;
	bool ok = 1;
	for (int i = s.size()-1; i>=0; i--) {
		if (s[i] == 'z') {
			ans[i] = 'a';
			ok = 0;
		}
		else {
			ans[i] = s[i] + 1;
			ok = 1;
			break;
		}
	}
	if(ok && ans != t) {
		cout << ans << endl;
	}
	else {
		cout << "No such string" << endl;
	}
	return 0;
}
