#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n,k,m;
	cin >> n >> k >> m;

	map<int,int> mp;
	int root = sqrt(n);
	int tp = n;
	for (int i=2; i<=root; i++) {
		while(tp % i == 0) {
			tp /= i;
			mp[i] ++ ;
		}
		if(mp.count(i) != 0) {
			mp[i] = (mp[i]+k-1)/k;
		}
	}
	if(tp != 1) {
		mp[tp] = 1;
	}

	int base = 1;
	for(auto i:mp) {
		int cnt = i.second;
		int num = i.first;
		while(cnt--){
			base *= num;
		}
	}

	// cout << "base = " << base << endl;
	int ans = m/base;
	cout << ans << endl;

	return 0;
}
