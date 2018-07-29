#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll pow_mod(ll x,ll n,ll mod){
	ll ans = 1;
	while(n>0){
		if(n & 1)ans = ans*x%mod;
		x = x*x%mod;
		n >>= 1;//右移一位
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n,m,k;
	cin>>n>>m>>k;

	if(n%2 != m%2 && k == -1){
		cout<<0<<endl;
	}
	else{
		cout<<pow_mod(pow_mod(2,(n-1),(ll)pow(10,9)+7),(m-1),(ll)pow(10,9)+7)<<endl;
	}
	return 0;
}
