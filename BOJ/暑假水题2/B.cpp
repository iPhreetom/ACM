#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,a,b;
	cin>>n>>a>>b;

	if(a*b >= 6*n){
		cout<<a*b<<endl;
		cout<<a<<' '<<b<<endl;
	}
	else{
		// int t = n;
		n *= 6;
		while(1){
			for(int i=min(a,b);i<=sqrt(n);i++){
				if(n%i == 0){
					if(max(i,n/i) >= max(a,b) && min(i,n/i) >= min(a,b)){
						cout<<n<<endl;
						if(a < b){
							cout<<min(i,n/i)<<' '<<max(i,n/i)<<endl;
						}
						else{
							cout<<max(i,n/i)<<' '<<min(i,n/i)<<endl;
						}
						return 0;
					}
				}
			}
			// n = t;
			n++;
		}
	}
	return 0;
}
