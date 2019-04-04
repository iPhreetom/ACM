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
	string ans;
	int index = 0;
	for (int j=0; j<t.size() && j < s.size(); j++, index++){
		ans.push_back((s[index]-'A' - (t[index]-'A') + 26)%26 + 'A');
	}
	int cnt = 0;
	for (int i=index; i<s.size(); i++){
		ans.push_back((s[i] - (ans[cnt++] - 'A') - 'A' + 26)%26 + 'A');
	}
	cout << ans << endl;
	return 0;
}
