#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,a,b;
	cin>>n>>a>>b;

	for(int i=0;i<=n;i+=a){
		if((n-i)%b == 0){
			int count = 1;
			for(int j=1;j<=i/a;j++){
				int t = a;
				while(t--){
					if(t){
						cout<<++count<<' ';
					}
					else cout<<++count-a<<' ';
				}
			}
			for(int j=1;j<=(n-i)/b;j++){
				int t = b;
				while(t--){
					if(t){
						cout<<++count<<' ';
					}
					else cout<<++count-b<<' ';
				}
			}
			return 0;
		}
	}
	cout<<-1<<endl;

	// int cur=0;
	//
	// for(int i=0;i<=n;i+=a){
	// 	if((n-i)%b == 0){
	// 		// int count = 1;
	// 		for(int j=i-a+1;j<=i;j++){
	// 			if(j==i)cout<<i-a+1;
	// 			else cout<<j+1;
	//
	// 		}
	// 	}
	// }

	return 0;
}
