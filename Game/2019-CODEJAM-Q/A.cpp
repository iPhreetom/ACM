#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	for(int cs=1; cs<=t; cs++) {
		string s;
		cin >> s;
		string a;
		string b;
		reverse(s.begin(),s.end());
		for (int i=0; i<s.size(); i++) {
		    if (s[i] == '4') {
				a.push_back('2');
				b.push_back('2');
			}
			else {
				a.push_back(s[i]);
				b.push_back('0');
			}
		}
		while(b.back() == '0') {
			b.pop_back();\
		}
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		cout << "Case #" << cs << ": " << a << ' ' << b << endl;
	}
	return 0;
}
