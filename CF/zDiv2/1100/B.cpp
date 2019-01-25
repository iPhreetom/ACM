// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

int n, m;
int cnt = 0;
string ans;
map<int,int> mp;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;

	for (int i=1; i<=m; i++){
	    int t;
		cin >> t;

		if(mp[t] == 0) {
			cnt++;
		}
		mp[t]++;


		if(cnt == n) {
			for (int j=1; j<=n; j++){
				if(--mp[j] == 0)cnt--;
			}
			ans.push_back('1');
		}
		else {
			ans.push_back('0');
		}

	}
	cout<<ans<<endl;
	return 0;
}
