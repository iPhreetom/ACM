// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

double a[100];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	double l;
	double pi = 3.1415926;
	while(cin>>n>>l){
		double ans = 0;
		for (int i=0; i<n; i++){
		    cin>>a[i];
			ans += sin(a[i]/180.0*pi)*l*l*0.5;
		}
		cout<<fixed<<setprecision(3)<<ans<<endl;
	}
	return 0;
}
