#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	int k;
	cin >> s >> k;

	int cntw = 0;
	int cntf = 0;
	for (int i=0; i<s.size(); i++){
		if(s[i] == '?')cntw++;
		if(s[i] == '*')cntf++;
	}

	int len = s.size() - cntw - cntf;
	int minlen = s.size() - cntw*2 - cntf*2;
	if(minlen > k || (cntf == 0 && len < k)) {
		cout << "Impossible" << endl;
	}
	else {
		if(cntf != 0) {
			string ans ;
			bool f = 1;
			for (int i=0; i<s.size()-1; i++){
				if(s[i] == '?' || s[i] == '*')continue;

				if(s[i+1] == '?'){

				}
				else if(s[i+1] == '*'){
					if(f){
						f = 0;
						while(minlen < k){
							ans.push_back(s[i]);
							minlen++;
						}
					}
				}
				else {
					ans.push_back(s[i]);
				}

			}
			if(s.back() != '?' && s.back() != '*') ans.push_back(s.back());
			cout << ans << endl;
		}
		else { //
			string ans ;
			for (int i=0; i<s.size()-1; i++){
				if(s[i] == '?' || s[i] == '*')continue;
				if(s[i+1] == '?') {
					if(len > k) {
						len --;
					}
					else {
						ans.push_back(s[i]);
					}
				}
				else {
					ans.push_back(s[i]);
				}
			}
			if(s.back() != '?') ans.push_back(s.back());
			cout << ans << endl;
		}
	}
	return 0;
}
