#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,x;
	cin>>n>>x;
	int t,ans =0;

	for(int i=1;i<=n;i++){
		int j = i;
		while(i){
			t = i%10;
			if(t == x)ans++;
			i/=10;
		}
		i = j;
	}
	cout<<ans<<endl;
	return 0;
}
