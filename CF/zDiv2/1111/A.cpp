#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s, t;
	set<char> abc;
	abc.insert('a');
	abc.insert('o');
	abc.insert('u');
	abc.insert('i');
	abc.insert('e');

	cin >> s >> t;
	if(s.size() != t.size()) {
		cout << "No" << endl;
		return 0;
	}
	else {
		for (int i=0; i<s.size(); i++){
			if(abc.count(s[i]) != abc.count(t[i])){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
