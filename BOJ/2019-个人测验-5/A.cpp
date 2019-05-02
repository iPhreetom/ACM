#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool judge(string s) {
	bool can = 1;
	for (int i=0; i<s.size(); i++) {
		if (s[i] != s[s.size()-i-1]) {
			can = 0;
		}
	}
	return can;
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;

	if (judge(s)) {
		string ans = s.substr(0,s.size()/2);
		ans += s[s.size()/2];
		string half = s.substr(s.size()/2);
		ans += half;
		cout << ans << endl;
	}
	else {
		for (int i=0; i<=s.size(); i++) {
			for (int j=0; j<s.size(); j++) {
				string tp = s.substr(0,i);
				tp += s[j];
				if(i!=s.size())tp += s.substr(i);
				if(judge(tp)){
					cout << tp << endl;
					return 0;
				}
			}
		}
		cout << "NA" << endl;
	}
	return 0;
}
