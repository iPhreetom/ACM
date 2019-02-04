#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string ss;
	cin >> ss;
	deque<char> s;
	for (int i=0; i<ss.size(); i++){
		s.push_back(ss[i]);
	}

	// 1
	while(!s.empty() && s.back()  != ']') {
		s.pop_back();
	}
	if(s.empty()) {
		cout << -1 << endl;
		return 0;
	}
	s.pop_back();

	// 2
	while(!s.empty() && s.back()  != ':') {
		s.pop_back();
	}
	if(s.empty()) {
		cout << -1 << endl;
		return 0;
	}
	s.pop_back();

	// 3
	while(!s.empty() && s.front()  != '[') {
		s.pop_front();
	}
	if(s.empty()) {
		cout << -1 << endl;
		return 0;
	}
	s.pop_front();

	// 4
	while(!s.empty() && s.front()  != ':') {
		s.pop_front();
	}
	if(s.empty()) {
		cout << -1 << endl;
		return 0;
	}
	s.pop_front();

	int cnt = 0;
	for (int i=0; i<s.size(); i++){
		if(s[i] == '|')cnt++;
	}
	cout << cnt + 4 << endl;
	return 0;
}
