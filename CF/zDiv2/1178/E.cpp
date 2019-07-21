// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	string ans;

	if (s.size() % 2 == 1) {
		// aba
		bool f = 1;
		for (int i=0; i<s.size(); i++){
			if (s[i] == 'a') {
				if (f) ans.push_back('a'), f = !f;
			}
			if (s[i] == 'b') {
				if (!f) ans.push_back('b'), f = !f;
			}
		}
		if (!ans.empty() && ans.back() == 'b') {
			ans.pop_back();
		}
		if (ans.size() >= s.size()/2) {
			cout << ans << endl;
			return 0;
		}

		// bab
		ans.clear();
		f = 1;
		for (int i=0; i<s.size(); i++){
			if (s[i] == 'b') {
				if (f) ans.push_back('b'), f = !f;
			}
			if (s[i] == 'a') {
				if (!f) ans.push_back('a'), f = !f;
			}
		}
		if (!ans.empty() && ans.back() == 'a') {
			ans.pop_back();
		}
		if (ans.size() >= s.size()/2) {
			cout << ans << endl;
			return 0;
		}

		// aca
		ans.clear();
		f = 1;
		for (int i=0; i<s.size(); i++){
			if (s[i] == 'a') {
				if (f) ans.push_back('a'), f = !f;
			}
			if (s[i] == 'c') {
				if (!f) ans.push_back('c'), f = !f;
			}
		}
		if (!ans.empty() && ans.back() == 'c') {
			ans.pop_back();
		}
		if (ans.size() >= s.size()/2) {
			cout << ans << endl;
			return 0;
		}

		// cac
		ans.clear();
		f = 1;
		for (int i=0; i<s.size(); i++){
			if (s[i] == 'c') {
				if (f) ans.push_back('c'), f = !f;
			}
			if (s[i] == 'a') {
				if (!f) ans.push_back('a'), f = !f;
			}
		}
		if (!ans.empty() && ans.back() == 'a') {
			ans.pop_back();
		}
		if (ans.size() >= s.size()/2) {
			cout << ans << endl;
			return 0;
		}

		// bcb
		ans.clear();
		f = 1;
		for (int i=0; i<s.size(); i++){
			if (s[i] == 'b') {
				if (f) ans.push_back('b'), f = !f;
			}
			if (s[i] == 'c') {
				if (!f) ans.push_back('c'), f = !f;
			}
		}
		if (!ans.empty() && ans.back() == 'c') {
			ans.pop_back();
		}
		if (ans.size() >= s.size()/2) {
			cout << ans << endl;
			return 0;
		}

		// cbc
		ans.clear();
		f = 1;
		for (int i=0; i<s.size(); i++){
			if (s[i] == 'c') {
				if (f) ans.push_back('c'), f = !f;
			}
			if (s[i] == 'b') {
				if (!f) ans.push_back('b'), f = !f;
			}
		}
		if (!ans.empty() && ans.back() == 'b') {
			ans.pop_back();
		}
		if (ans.size() >= s.size()/2) {
			cout << ans << endl;
			return 0;
		}
	}
	else {
		if (s.size() == 2) {
			cout << s[0] << endl;
		}
		else {
			deque<char> que;
			for (int i=0; i<s.size(); i++){
				que.push_back(s[i]);
			}
			string s1,s2;
			while(que.size() > 2) {
				set<char> st;
				st.insert(que.front());
				que.pop_back();
				if (st.find(que.front()) != st.end()) {
					st.insert();
				}
				else {

				}
			}
		}
	}
	return 0;
}
