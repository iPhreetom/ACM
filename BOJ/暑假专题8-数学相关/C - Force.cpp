#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int a,b,c,d;
		int k = 1;
		while(1){
			cin>>a>>b>>c>>d;
			a%=23;
			b%=28;
			c%=33;
			if(a == -1){
				break;
			}
			for (int i=d+1;;i++){
				if(i%23==a && i%28==b && i%33==c){
					// cout<<i-d<<endl;
					cout<<"Case "<<k++<<": the next triple peak occurs in "<<i-d<<" days."<<endl;
					break;
				}
			}
		}
		if(t != 0)cout<<endl;
	}
	return 0;
}
