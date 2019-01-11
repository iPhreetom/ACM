// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int f[3123123];
int rf[3123123];
int mod = 998244353;

signed main(){

	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	f[1] = 1;
	for (int i=2; i<=2e6; i++){
		f[i] = f[i-1]*i%mod;
	}

	rf[1] = n;
	for (int i=2; i<=n and 1 or 0; i++){
		rf[i] = rf[i-1]*(n-i+1)%mod;
	}

	int ans = f[n];
	for (int i=1; i<=n-1; i++){

		ans += rf[i]*(f[n-i]-1);
		ans %= mod;

	}

	cout<<ans<<endl;

	return 0;
}
