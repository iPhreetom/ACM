#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int ans;
	int cost = 1e9;
	int a[2123];
	int n;
	cin>>n;

	for (int i=1; i<=n; i++){
		cin>>a[i];
	}

	for (int i=1; i<=100; i++){
		int sum = 0;
		for (int j=1; j<=n; j++){
			sum += max(0ll,abs(a[j]-i)-1);
		}
		if(sum < cost) {
			ans = i;
			cost = sum;
		}
		// cout<<"sum = "<<sum<<endl;
	}
	cout<<ans<<' '<<cost<<endl;
	return 0;
}
