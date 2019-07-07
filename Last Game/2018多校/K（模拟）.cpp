#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0);
	string qw= "adsfasdf-1";
	double d = strtol(qw.c_str(),NULL,0);
	cout << "d = " << d << endl;
	int t;
	cin >> t;
	while(t--){
		int h,m;
		cin >> h >> m;
		string s;
		cin >> s;
		string tp = s.substr(4);
		string ht,mt;
		bool st = false;
		for (int i=0; i<tp.size(); i++) {
			if (tp[i] == '.') {
				st = true;
				continue;
			}
			if (!st) {
				ht.push_back(tp[i]);
			}
			else {
				mt.push_back(tp[i]);
			}
		}
		if (s[3] == '+') {
			h += strtol(ht.c_str(),NULL,0);
		}
		else {
			h -= atoi(ht.c_str());
		}
		if (!mt.empty()) {
			if (s[3] == '+') {
				m += 6*atoi(mt.c_str());
			}
			else {
				m -= 6*atoi(mt.c_str());
			}
		}
		if (m < 0) {
			h--;
			m += 60;
		}
		if (m >= 60) {
			h++;
			m -= 60;
		}
		h -= 8;
		h += 48;
		h %= 24;

		// cout << h << ':' << m << endl;
		printf("%02d:%02d\n",h,m);
	}
	return 0;
}
