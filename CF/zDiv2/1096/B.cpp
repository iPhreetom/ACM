#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int mod = 998244353;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(s[0] != s[n-1]) {
		int len1 = 0, len2 = 0;
		for (int i=0; i<s.size(); i++){
			if(s[i] == s[0]) {
				len1 ++;
			}
			else break;
		}
		for (int i=n-1; i>=0; i--) {
			if(s[i] == s[n-1]) {
				len2 ++;
			}
			else break;
		}
		int ans = 1;
		ans += len1;
		ans += len2;
		cout << ans%mod << endl;
	}
	else {
		int len1 = 0, len2 = 0;
		for (int i=0; i<s.size(); i++){
			if(s[i] == s[0]) {
				len1 ++;
			}
			else break;
		}
		for (int i=n-1; i>=0; i--) {
			if(s[i] == s[n-1]) {
				len2 ++;
			}
			else break;
		}
		int ans = 0;
		ans += (len1+1) * (len2+1);
		cout << ans%mod <<endl;
	}
	return 0;
}
