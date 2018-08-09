// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const double pi = acos(-1);

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		double a,b;
		cin>>a>>b;
		double ans = 2*b+pi*a;
		int tp = ans*1000000;
		ans = tp/1000000.0;
		cout<<fixed<<setprecision(6)<<ans<<endl;
	}
	return 0;
}
