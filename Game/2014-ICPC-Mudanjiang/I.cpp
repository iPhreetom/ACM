// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	double e = pow(2,1/log(2));
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		double ans = 0;

		cin>>n>>s;
		if(s == "bit"){
			for (int i=0; i<n; i++){
				int tp;
				cin>>tp;
				double p = tp;
				if(p != 0)ans += (p/100)*log2(p/100);
			}
		}
		if(s == "nat"){
			for (int i=0; i<n; i++){
				int tp;
				cin>>tp;
				double p = tp;
				if(p != 0)ans += (p/100)*log(p/100);
			}
		}
		if(s == "dit"){
			for (int i=0; i<n; i++){
				int tp;
				cin>>tp;
				double p = tp;
				if(p != 0)ans += (p/100)*log10(p/100);
			}
		}

		if(ans == 0){
			cout<<fixed<<setprecision(15)<<ans<<endl;
		}
		else{
			cout<<fixed<<setprecision(15)<<-ans<<endl;
		}
	}
	return 0;
}
