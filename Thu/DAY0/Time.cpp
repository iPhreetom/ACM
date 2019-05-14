#include<iostream>
#include<cstdio>
#define int long long
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s,t;
	cin >> s >> t;
	int be = 0;
	int reb = 0;

	be += s.back()-'0'; s.pop_back();
	be += (s.back()-'0')*10; s.pop_back();
	s.pop_back();
	be += (s.back()-'0')*60; s.pop_back();
	be += (s.back()-'0')*10*60; s.pop_back();
	s.pop_back();
	be += (s.back()-'0')*3600; s.pop_back();
	be += (s.back()-'0')*10*3600; s.pop_back();

	reb = be;
	s = t;
	be = 0;

	be += s.back()-'0'; s.pop_back();
	be += (s.back()-'0')*10; s.pop_back();
	s.pop_back();
	be += (s.back()-'0')*60; s.pop_back();
	be += (s.back()-'0')*10*60; s.pop_back();
	s.pop_back();
	be += (s.back()-'0')*3600; s.pop_back();
	be += (s.back()-'0')*10*3600; s.pop_back();

	if (be < reb) {
		cout << 3600*24 - reb + be << endl;
	}
	else {
		cout << be - reb << endl;
	}
	return 0;
}
