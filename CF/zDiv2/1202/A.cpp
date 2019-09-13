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
		string s, t;
		cin >> s >> t;
		reverse(s.begin(),s.end());
		reverse(t.begin(),t.end());
		int index = 0;
		for (int i=0; i<t.size(); i++){
			if (t[i] == '1') {
				index = i;
				break;
			}
		}
		if (index >= s.size()){
			cout << 0 << endl;
		}
		else {
			int cnt = 0;
			for (int i=index; i<s.size(); i++){
				if (s[i] == '1') {
					cout << cnt << endl;
					break;
				}
				else cnt++;
			}
		}
	}
	return 0;
}
