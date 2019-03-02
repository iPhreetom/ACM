#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

bool abigger(string &a, string &b) {
	if(a.size() > b.size()){
		return 1;
	}
	else {
		if(a.size() < b.size()){
			return 0;
		}
		else{ // 相等
			return a>b;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin>>n;
		string s;
		cin>>s;
		if(s.size() >= 3) {
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << s[0] << ' ' << s.substr(1) << endl;
		}
		else {
			if(s[0] >= s[1]) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
				cout << 2 << endl;
				cout << s[0] << ' ' << s.substr(1) << endl;
			}
		}
	}
	return 0;
}
