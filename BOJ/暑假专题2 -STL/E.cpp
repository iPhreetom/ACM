#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n;
		int mx = -1e17;
		int dif = -1e17;
		cin>>n;
		for(int i=0;i<n;i++){
			int t;
			cin>>t;

			dif = max(dif,mx-t);
			mx = max(mx,t);
		}
		cout<<dif<<endl;
	}
	return 0;
}
