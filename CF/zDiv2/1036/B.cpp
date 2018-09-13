// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int q;
	cin>>q;
	for (int i=0; i<q; i++){
	    int x,y,k;
		cin>>x>>y>>k;
		if(max(abs(x),abs(y)) > k){
			cout<<-1<<endl;
		}
		else{
			x = abs(x);
			y = abs(y);

			int ans = min(x,y);

			int diff = abs(x-y);

			k -= min(x,y);

			if(diff % 2 == 1){
				ans += k-1;
			}
			else{// diff is even
				if(k%2 == 0){
					ans+=k;
				}
				else{
					ans = ans+k-2;
				}
			}



			cout<<ans<<endl;
		}
	}
	return 0;
}
