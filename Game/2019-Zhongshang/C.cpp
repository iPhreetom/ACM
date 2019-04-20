// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
		string bitstr;
		for (int i=0; i<s.size(); i++){
			string tmp;
			int val = s[i]+0;
			for (int j=7; j>=0; j--){
				if(val >= (1<<j)) {
					val -= (1<<j);
					tmp.push_back('1');
				}
				else tmp.push_back('0');
			}
			reverse(tmp.begin(),tmp.end());
			bitstr += tmp;
		}

		bool f = 1;
		for (int i=0; i<bitstr.size(); i+=6){
			int val = 0;
			for (int j=1; j<=6; j++){
				if(bitstr[i+j-1] == '1')val += (1<<(6-j));
			}
			cout << val << ' ';
			// if(f) {
			// 	cout << val;
			// 	f = !f;
			// }
			// else cout << ' ' << val;
		}

	return 0;
}
