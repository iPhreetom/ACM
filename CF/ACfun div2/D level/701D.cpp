#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;

	double l,v1,v2;

	cin>>n>>l>>v1>>v2>>k;
	if(v1 < v2){
		int cint = (n+k-1)/k;
		double c = cint;

		double x = ((v2*v1+v2*v2)*l)/(2*v1*v2*(c-1)+v1*v2+v2*v2);
		double t = x/v2 + (l-x)/v1;
		// cout<<x<<endl;
		// cout<<c<<endl;
		cout<<fixed<<setprecision(9)<<t<<endl;
	}
	else{
		cout<<fixed<<setprecision(9)<<((double)l)/v1<<endl;
	}
	return 0;
}
