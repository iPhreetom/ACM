#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int a[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<2*n;i++){
		cin>>a[i];
	}

	sort(a,a+2*n);

	int ans1 = 0;
	// bool inoneline=1;
	// for(int i=0;i<n;i++){
	// 	if((a[i]-a[0])*(a[2*n-1]*a[i+n]) != (a[i+n]-a[n])*(a[n-1]-a[i]))inoneline=0;
	// }
	// if(inoneline){
	// 	cout<<0<<endl;
	// 	return 0;
	// }

	ans1 = (a[n-1]-a[0])*(a[n*2-1]-a[n]);

	for(int i=1;i<n;i++){
		ans1 = min(ans1,(a[2*n-1]-a[0])*(a[i+n-1]-a[i]));
	}
	cout<<ans1<<endl;

	return 0;
}
