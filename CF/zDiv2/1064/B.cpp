// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int q;
		cin>>q;
		int cnt = 0;
		while(q){
			if(q&1)cnt++;
			q>>=1;
		}
		int ans = pow(2,cnt);
		cout<<ans<<endl;
	}
	return 0;
}
