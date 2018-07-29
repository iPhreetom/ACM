#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll root(ll x){
	ll l=0,r=1e9;
	while(l+1<r){
		ll mid = l+(l+r)/2;
		if(mid * mid < x)l = mid;
		else r=mid;
	}
	return l;
}

set<ll> a;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll len = root(1e9);
	for(ll i=1;i<=len;i++){
		a.insert(i*i-1);

	}

	return 0;
}
