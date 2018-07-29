
#include<bits/stdc++.h>
using namespace std;

long long xl,xr,yu,yd;
long long x,y;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if(i == 0){
			xl = x;
			xr = x;
			yu = y;
			yd = y;
		}
		else {
			if(x < xl)xl = x;
			if(x > xr)xr = x;
			if(y > yu)yu = y;
			if(y < yd)yd = y;
		}
	}
	long long ans = max(yu-yd,xr-xl);
	cout<<ans*ans<<endl;

	return 0;
}
