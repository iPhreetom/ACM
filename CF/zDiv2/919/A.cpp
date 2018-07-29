#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	long double n,m,mn=10000000,x,y;
	cin>>n>>m;

	// long double a[212345];
	for(int i=0;i<n;i++){
		cin>>x>>y;
		mn = min(x/y,mn);
	}

	cout<<fixed<<setprecision(9)<<m*mn<<endl;
	return 0;
}
