#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

set<int> s;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;

		int mod = pow(10,n);
		int mx = k;

		for(int i=0;i<2123456;i++){
			k *= k;
			while(k>=mod){
				k/=10;
			}
			mx = max(mx,k);
		}
		cout<<mx<<endl;
	}
	return 0;
}
