// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(1){
		cin>>n;
		if(n == 0)break;

		vector<double> a;
		for (int i=0; i<n; i++){
			double t;cin>>t;
			a.push_back(t);
		}
		sort(a.rbegin(),a.rend());

		if(a.size() <= 2){
			cout<<"0.00"<<endl;
		}
		else{
			cout<<fixed<<setprecision(2);
			double ans = 0;
			for (int i=0; i<a.size()-2; i++){
				if(a[i+1]+a[i+2] > a[i]){
					double p  = a[i] + a[i+1] + a[i+2];
					p/=2;
					ans += sqrt(
						p
						*(p-a[i])
						*(p-a[i+1])
						*(p-a[i+2]) );
					i+=2;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
