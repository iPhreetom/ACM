// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

inline bool check(char& ch) {
	if (ch == '+' || ch == '*') return true;
	else return false;
}

inline bool isnum(char &ch) {
	for (int i=0; i<=9; i++){
		if (ch == i+'0') return true;
	}
	return false;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		int f = 0;
		if (check(s[0])) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		if (s[0] == '0') f = 2;
		reverse(s.begin(),s.end());
		string ans;
		bool can = 1;
		if (f == 2) {
			ans.push_back('0');
			s.pop_back();
		}

		while (!s.empty()) {
			char ch = s.back(); s.pop_back();
			// cout<<"f = "<<f<<endl;
			if (f == 0) {
				if (ch == '?') ans.push_back('9');
				else if (check(ch)) ans.push_back(ch), f = 1;
				else if (isnum(ch)) ans.push_back(ch);
			}
			else if (f == 1) {
				if (check(ch)) {can = 0; break;}
				else if (ch == '?') ans.push_back('9'), f = 0;
				else if (ch == '0') ans.push_back('0'), f = 2;
				else if (isnum(ch)) ans.push_back(ch), f = 0;
			}
			else if (f == 2) {
				if (isnum(ch)) {can = 0; break;}
				else if (ch == '?') ans.push_back('+'), f = 1;
				else if (check(ch)) ans.push_back(ch), f = 1;
			}
			// cout<<"f2` = "<<f<<endl;
		}
		if (!can || f == 1) {
			cout << "IMPOSSIBLE" << endl;
		}
		else cout << ans << endl;
	}
	return 0;
}
