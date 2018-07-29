
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n,m,a,b;
	cin>>n>>m>>a>>b;

	if(n%m==0){
		cout<<0<<endl;
	}
	else{
		if(n < m){
			cout<<min((m-n)*a,n*b)<<endl;
		}
		else{
			ll last=1,now=1,t=1;
			last = n/m * m;
			now = n/m * m + m;

			cout<<min((n-last)*b,a*(now-n))<<endl;
		}

	}
	return 0;
}
