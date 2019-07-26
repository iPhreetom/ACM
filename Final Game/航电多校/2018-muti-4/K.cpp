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
		bool can = true;
		cin >> s;

		if (s.size() == 1) {
			if (check(s[0])) cout << "IMPOSSIBLE" << endl;
			else if (s[0] == '?') cout << "1" << endl;
			else cout << s << endl;
			continue;
		}
		if (s.size() == 2) {
			if (check(s[0]) || check(s[1]) || s[0] == '0') cout << "IMPOSSIBLE" << endl;
			else {
				if (s[0] == '?') s[0] = '1';
				if (s[1] == '?') s[1] = '1';
				cout << s << endl;
			}
			continue;
		}

		// symbol
		for (int i=1; i<(int)s.size(); i++){
			if (check(s[i])&&check(s[i-1])) can = false;
		}
		if (check(*s.begin()) || check(s.back())) can = false;

		// front zero // 10001
		for (int i=0; i<(int)s.size()-1; i++){
			if (s[i] == '0' && isnum(s[i+1])) can = false;
		}

		// 0 and symbol
		int len = (int)s.size();
		// 0?+
		for (int i=0; i<len-2; i++){
			if (s[i] == '0' && s[i+1] == '?' && check(s[i+2])) can = false;
		}
		// 0?
		if (s[len-2] == '0') can = false;

		if (!can) cout << "IMPOSSIBLE" << endl;
		else {
			for (int i=0; i<len; i++){
				if (s[i] == '?') s[i] = '1';
			} // 0*0
			cout << s << endl;
		}
	}
	return 0;
}
