// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;

	int ans = 0;
	string out;
	for (int i=0; i<s.size(); ){
		if (i == s.size()-1) {
			ans++;
			break;
		}
		if (s[i] != s[i+1]) {
			out.push_back(s[i]);
			out.push_back(s[i+1]);
			i += 2;
		}
		else {
			i++;
			ans++;
		}
	}
	cout << ans << endl;
	cout << out << endl;
	return 0;
}
