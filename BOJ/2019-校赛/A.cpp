// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,p,q;
	cin >> n >> p >> q;
	vector<string> mp;
	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		sort(s.begin(),s.end());
		mp.push_back(s);
	}

	int m;
	cin >> m;
	int index = 0;
	int ans = 0;
	int cnt = 0;
	for (int i=1; i<=m; i++){
		string s;
		cin >> s;
		sort(s.begin(),s.end());
		if(s == mp[index]) {
			cnt++;
			index++;
			ans += p;
			ans += (cnt-1)*q;
		}
		else {
			cnt = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
