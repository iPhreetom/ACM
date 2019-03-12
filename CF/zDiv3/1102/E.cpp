#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int mod = 998244353;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	vector<int> v(212345, 0);
	for (int i=1; i<=n; i++) {
		cin >> v[i];
	}

	map<int,int> mp;
	for (int i=n; i>=1; i--) {
		if(mp.count(v[i]) == 0) {
			mp[v[i]] = i;
		}
	}

	int cnt = 0;
	for (int i=1; i<=n; i++){
		int rt = mp[v[i]];
		for (int j=i+1; j<=rt; j++) {
			rt = max(rt, mp[v[j]]);
		}
		i = rt;
		cnt++;
	}

	cnt--;
	int ans = 1;
	for (int i=1; i<=cnt; i++){
		ans *= 2;
		while(ans >= mod) ans -= mod;
	}
	cout << ans << endl;
	return 0;
}
