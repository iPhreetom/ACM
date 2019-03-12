#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

string s;
string ans;
bool vis[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> s;

	int index = (s.size()-1)/2;
	bool rt = 0;
	while(ans.size() != s.size()) {
		if(rt) {
			while(index < s.size()) {
				if(!vis[index]) {
					vis[index] = 1;
					ans.push_back(s[index]);
					break;
				}
				index++;
			}
			rt = 0;
		}
		else {
			while(index >= 0) {
				if(!vis[index]) {
					ans.push_back(s[index]);
					vis[index] = 1;
					break;
				}
				index--;
			}
			rt = 1;
		}
	}
	cout << ans << endl;
	return 0;
}
