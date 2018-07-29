// CF 1004B
// 	一句话描述：
// 		猜结论的题
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


string ans ;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n,m;
	cin>>n>>m;

	bool f=1;
	for(int i=0;i<n;i++){
		if(f)ans.push_back('1'),f=!f;
		else ans.push_back('0'),f=!f;
	}
	cout<<ans<<endl;
	// int a[1123];
	// ll ans = 0;
	// ll l,r;
	// for(int i=0;i<m;i++){
	// 	// cin>>a[i];
	// 	cin>>l>>r;
	// 	ans += ((r-l+1)/2) * ((r-l+2)/2);
	// 	// cout<<ans<<endl;
	// }
	// cout<<ans<<endl;
	// }cout<<ans<<endl;
	return 0;
}
