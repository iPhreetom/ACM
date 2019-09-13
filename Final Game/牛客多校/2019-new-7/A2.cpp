// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		vector<string> ans;
		int zero = 0;
		int one = 0;
		int szero = 0;
		string tmp;
		for (int i=0; i<s.size(); i++){
			if (s[i] == '1') {
				one++;
				tmp.push_back('1');
			}
			else {
				if (zero == 0) {
					if (one != 0) { // put

					}
					else { // one == 0;
						zero++;
					}
				}
				else {
					// zero is not zero
					if (szero == zero) { //put and reflash

					}
					else {
						szero++;
					}
				}
			}
		}
	}
	return 0;
}
