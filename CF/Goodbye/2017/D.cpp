#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

ll exgcd(ll a,ll b,ll &x,ll &y){
	ll result = a;
	if(b == 0){
		x = 1;
		y = 0;
	}
	else{
		result = exgcd(b,a%b,y,x);
		y -= (a/b)*x;
	}
	return result;
}



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int k,pa,pb;
	cin>>k>>pa>>pb;

	int fenzi,fenmu;
	
	return 0;
}
