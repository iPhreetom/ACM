// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool dig(char ch) {
	if (ch >= '0' && ch <= '9') return true;
	return false;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;

	while (n--) {
		string t;
		cin >> t;
		if (t == s) {cout << "+\n"; continue;}

		bool f = 0;
		for (int i=0; i<t.size() && i<s.size(); i++){
			if (s[i] != t[i]) {
				f = 1;

				if (dig(s[i]) && dig(t[i])) {
					string d = "1";
					for (int j=i; j<s.size(); j++){
						if (dig(s[j])) d.push_back(s[j]);
						else break;
					}
					int v1 = atol(d.c_str());

					d.clear();
					d = "1";
					for (int j=i; j<t.size(); j++){
						if (dig(t[j])) d.push_back(t[j]);
						else break;
					}
					int v2 = atol(d.c_str());

					if (v1 < v2) {
						cout << "+\n";
						break;
					}
					else {
						cout << "-\n";
						break;
					}
				}
				else if(dig(s[i]) && !dig(t[i])) {
					if (i!=0 && dig(t[i-1])) {
						cout << "-\n";
					}
					else {
						cout << "+\n";
					}
					break;
				}
				else if(!dig(s[i]) && dig(t[i])) {
					if (i!=0 && dig(t[i-1])) {
						cout << "+\n";
					}
					else {
						cout << "-\n";
					}
					break;
				}
				else if(!dig(s[i]) && !dig(t[i])) {
					if (s[i] < t[i]) {
						cout << "+\n";
						break;
					}
					else {
						cout << "-\n";
						break;
					}
				}

			}
		}

		if (f == 0) {
			if (s.size() > t.size()) {
				cout << "-\n";
			}
			else {
				cout << "+\n";
			}
		}
	}
	return 0;
}
