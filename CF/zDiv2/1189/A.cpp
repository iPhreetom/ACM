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
	int one = 0;
	for (int i=0; i<s.size(); i++){
		if (s[i] == '1') one++;
	}
	int zero = s.size()-one;


	if (one != zero) {
		cout << 1 << endl;
		cout << s << endl;
	}
	else {
		cout << 2 << endl;
		cout << s[0];
		if (s.size() > 1) {
			cout << ' ' << s.substr(1);
		}
		cout << endl;
	}
	return 0;
}
