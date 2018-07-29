
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll n,k;
vector<ll> a;
set<ll> s;
ll ans;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		ll t;
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		auto id = upper_bound(a.begin(),a.begin()+n,a[i]);
		// cout<<*id<<endl;
		if(id!=a.end() && *id != a[i] && *id <= a[i]+k)ans++;
	}
	cout<<n-ans<<endl;
	return 0;
}
