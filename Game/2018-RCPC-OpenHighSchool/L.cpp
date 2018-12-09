// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t,n,a,b,k;
	cin>>t>>n>>a>>b>>k;
	int ans = 0;

	if(min(a,b) > t){
		if(n >= k){
			cout<<t<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	else{
		// min(a,b) <= t
		if(n%k == 0){
			ans += n/k*min(a,b);
			if(ans >= t){// too much
				cout<<t<<endl;
				return 0;
			}
			t -= ans;

			int dif = max(a,b)-min(a,b);
			int num = n/2;
			if(dif > t){// to many class
				if(num > k){
					cout<<ans + t<<endl;
				}
				else{
					cout<<ans<<endl;
				}
			}
			else{
				// dif <= t
				// t remain people
				// num remain class
				ans += min(t,(num/k)*dif);
				// for we can use the class one time
				// so we just divide the sum using the k is ok
			}
		}
		else{

		}
	}

	return 0;
}
