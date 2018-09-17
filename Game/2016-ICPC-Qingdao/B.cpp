// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	double dif = log(2);
	// cout<<dif<<endl;
	int t;
	cin>>t;
	while(t--){
		double l,d;
		cin>>l>>d;

		if(l <= d){
			double ans = 0;
			cout<<fixed<<setprecision(6)<<ans<<endl;
			continue;
		}

		l /= d;
	 	d = 1;
		double ans = 1;
		ans += log2(l)*dif;

		cout<<fixed<<setprecision(6)<<ans<<endl;
	}
	return 0;
}
