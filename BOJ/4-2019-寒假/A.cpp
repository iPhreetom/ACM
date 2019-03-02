#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int r,b,q;
	cin>>r>>b>>q;

	int ans = min(r,min(b,q) );

	if(ans >= 1) {
		ans3 = 1;
		ans3 += (r-1)/3 + (b-1)/3 + (q-1)/3;
	}
	if(ans >= 2) {
		ans4 = 2;
		ans4 += (r-2)/3 + (b-2)/3 + (q-2)/3;
	}

	cout<<max(ans2,max(ans3,ans4))<<endl;
	return 0;
}
