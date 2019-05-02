#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	for(int cs=1; cs<=t; cs++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string ans;
		for (int i=0; i<s.size(); i++) {
		    if(s[i] == 'S')ans.push_back('E');
			else ans.push_back('S');
		}
		cout << "Case #" << cs << ": " << ans << endl;
	}
	return 0;
}
