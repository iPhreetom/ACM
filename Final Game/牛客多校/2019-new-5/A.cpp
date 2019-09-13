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
	while(T--){
		int n;
		cin >> n;
		string s = to_string(n);
		string ans = s;
		int now = 0;
		for (int i=0; i<s.size(); i++){
			now += s[i]-'0';
		}

		int temp = now;
		while(now % n != 0) {
			now %= n;
			ans += s;
			now += temp;
		}
		cout << ans << endl;
	}
	return 0;
}
