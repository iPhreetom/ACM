// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;

	int ans = 0;

	for (int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i-1] > 0){
			a[i] -= (k-a[i-1]);
			a[i-1] = 0;
			ans++;
		}

		if(a[i] >= k){
			int cnt = a[i]/k;
			ans += cnt;
			a[i] -= k*cnt;
		}
	}

	if(a[n]>0){
		ans++;
	}

	cout<<ans<<endl;

	return 0;
}
