#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		if(s.size() % 4 != 0) {
			cout << "No" << endl;
		}
		else {
			bool ok = 1;
			for (int j=0; j<s.size(); j+=4) {
				if(s[j] == '2' && s[j+1] == '0' && s[j+2] == '5' && s[j+3] == '0') {
					continue;
				}
				else {
					ok = 0;
				}
			}
			if(ok) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}
