// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin >> n >> k;
	map<int,int> mp;
	for (int i=0; i<n; i++){
		int t;
		cin >> t;
		mp[t] ++;
	}
	int ans = 0;
	int num = 1;
	for (auto i:mp) {
		int val = i.second;
		if (val % 2 == 1) {
			if (num) {
				ans += val;
				num = 0;
			}
			else {
				ans += val-1;
				num++;
			}
		}
		else {
			ans += val;
		}
	}
	cout << ans << endl;
	return 0;
}
