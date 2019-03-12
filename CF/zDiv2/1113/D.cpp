#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	char ch = s[0];
	bool dif = 0;

	if(s.size() < 4){
		cout << "Impossible" << endl;
		return 0;
	}

	if(s.size()%2 == 1) {
		int mid = s.size()/2;
		for (int i=0; i<s.size(); i++) {
			if(s[i] != ch && i != mid)dif = 1;
		}
	}
	else {
		for (int i=0; i<s.size(); i++) {
			if(s[i] != ch)dif = 1;
		}
	}

	if(!dif || s.size() < 4){
		cout << "Impossible" << endl;
	}
	else {
		string tp;
		for (int i=0; i<s.size()-1; i++) {
			bool ok = 1;
			tp = s.substr(i+1)+s.substr(0,i+1);
			for (int j=0; j<tp.size(); j++) {
				if(tp[j] != tp[tp.size()-j-1]){
					ok = 0;
					break;
				}
			}
			if(ok && s != tp) {
				cout << 1 << endl;
				return 0;
			}
		}
		cout << 2 << endl;
		// if(s.size()%2 == 0) {
		// }
		// else {
		// 	cout << 2 << endl;
		// 	return 0;
		// }
	}
	return 0;
}
// op\o\po
// ppopp
