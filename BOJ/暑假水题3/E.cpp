#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int s,t,q;
	cin>>t>>s>>q;

	int ans = 0;
	while(s < t){
		s *= q;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
