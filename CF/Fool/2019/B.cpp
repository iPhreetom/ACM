#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	set<int> s;
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(12);
	s.insert(30);
	s.insert(31);
	s.insert(46);
	if(s.count(t) == 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
	return 0;
}
