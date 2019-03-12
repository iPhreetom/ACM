#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	string ans ;
	int index = 0;
	for (int i=1; i<=n; i+=(++index)){
		ans.push_back(s[i-1]);
	}
	cout << ans << endl;
	return 0;
}
