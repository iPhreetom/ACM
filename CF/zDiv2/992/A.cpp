#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> a;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n;
	cin>>n;

	a.insert(0);
	for(int i=0;i<n;i++){
		ll t;
		cin>>t;
		a.insert(t);
	}
	cout<<a.size()-1<<endl;
	return 0;
}
