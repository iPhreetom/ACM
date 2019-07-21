// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int mod = 998244353;
	int ans = 1;
	for (int i=1; i<=n+m; i++){
		ans *= 2;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
