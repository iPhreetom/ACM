// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, p, k;
	cin >> n >> p >> k;
	vector<int> v;
	for (int i=0; i<n; i++){
		int t;
		cin >> t;
		v.push_back(t);
	}
	map<int,int> mp;
	int ans = 0;
	for (int i=0; i<n; i++){
		int tmp = (v[i]*v[i])%p;
		tmp = tmp*tmp%p;
		tmp = tmp-(k*v[i])%p;
		tmp += p;
		tmp %= p;
		ans += mp[tmp];
		mp[tmp]++;
	}
	cout << ans << endl;
	return 0;
}
