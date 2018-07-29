#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

set<ll> s;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=k;i++){
		if(s.count(n%i) == 0){
			s.insert(n%i);
		}
		else{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
