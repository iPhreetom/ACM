#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t-- ) {
		string s;
		cin >> s;
		sort(s.begin(),s.end());

		bool same = 1;
		if(s.size() == 1) {
			cout << -1 << endl;
			continue;
		}
		for (int i=1; i<s.size(); i++){
			if(s[i] != s[i-1])same = 0;
		}
		if(same) {
			cout << -1 << endl;
			continue;
		}
		cout << s << endl;
	}
	return 0;
}
