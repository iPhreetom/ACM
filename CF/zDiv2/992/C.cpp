#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll qdd=1e9+7;
ll qpow(ll a,ll b)
{
	if(b==0)return 1;
	if(b==1)return a%qdd;
	if(b%2)return ((qpow(a,b/2)%qdd)*(qpow(a,b/2)%qdd)%qdd)*(a%qdd)%qdd;
	else return (qpow(a,b/2)%qdd)*(qpow(a,b/2)%qdd)%qdd;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll x,k;
	cin>>x>>k;
	if(x==0){
		cout<<0<<endl;
		return 0;
	}
	ll ans=qpow(2,k+1)*(x%qdd)%qdd-qpow(2,k)+1;
	ans=(ans+qdd)%qdd;
	cout<<ans<<endl;
	return 0;
}
