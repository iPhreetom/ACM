// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

unsigned int ans ;
vector<unsigned int> arr;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
	    unsigned int a,b;
		cin>>a>>b;
		arr.push_back(a);
		arr.push_back(b);
		if(ans == 0){
			ans = a*b;
		}
		else {
			a = a*b;
			ans = __gcd(ans,a);
		}
	}
	if(ans == 1)cout<<-1<<endl;
	else{
		unsigned int i;
		bool findit = 0;
		for (int i=0; i<arr.size(); i++){
			unsigned int q = __gcd(ans,arr[i]);
			if(q!=1){
				unsigned int j;
				for (j=2; j<=sqrt(q); j++){
					if(q % j == 0){
						findit=1;
						break;
					}
				}
				if(!findit)cout<<q<<endl;
				else cout<<j<<endl;
				break;
			}
		}
		// if(!findit)cout<<ans<<endl;
		// cout<<ans<<endl;
	}
	return 0;
}
