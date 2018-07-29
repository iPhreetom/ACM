#include<bits/stdc++.h>
#define int long long
using namespace std;

// may
int n,m;
int sum;
double ans;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,d;
		cin>>x>>d;
		sum += x*n;

		if(d > 0){
			sum += d*(n-1)*n/2;
		}
		else{
			// int d/2;
			sum += d*((n/2)*(n/2+1)/2);
			if(n % 2 == 1){
				sum += d*((n/2)*(n/2+1)/2);
			}
			else{
				if(n!=1 && n!= 2){
					sum += d*((n/2-1)*(n/2)/2);
				}
			}
		}
	}
	ans = sum;
	ans /= n;
	cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}
