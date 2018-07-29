
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll a[112345];
ll n;

bool check(ll mid){
	ll d=0;
	ll cnt=1;
	bool get=0;
	for(int i=0;i<=n;i++){
		if(i == n){
			if(d==0)return 1;
			if(cnt != d)return 0;
		}
		if(!get){
			if(a[i] >= mid){
				d = (i+1);
				get=1;
			}
		}
		else{
			if(a[i]>=mid){
				if(cnt != d)return 0;
				cnt = 1;
			}
			else{
				cnt++;
			}
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll l=0,r=1e9+1;
	while(l+1<r){
		ll mid = l+(r-l)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	return 0;
}
