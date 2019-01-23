#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		if(l*2 <= r){
			cout<<l<<' '<<l*2<<endl;
		}
	}
	return 0;
}
