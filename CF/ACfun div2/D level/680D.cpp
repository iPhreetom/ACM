#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



map<ll,ll> mp;
vector<ll> lis;
ll m;
ll mx=0;

void print(ll m){

	ll tr = 0;
	ll ans = 0;
	while(tr<m){
		auto c = lower_bound(lis.begin(),lis.end(),(m-tr));
		if(*c > (m-tr))c--;

		ll mn = (m-tr)/(*c);
		if(mn == 0)break;

		ans+= mn;
		tr += mn*(*c);
		// cout<<ans<<' '<<tr<<endl;
	}
	cout<<"MAX is :"<<m<<"  "<<ans<<' ';
	mx = max(mx,ans);

	ll chose=0;
	ll index=0;
	ll pro=1;
	ans=0;
	// bool f=1;
	while(chose < m){
		// cout<<"___"<<endl;
		ll mn = min((lis[index+1]-max(chose,1ll))/lis[index] , (m-chose)/lis[index]);
		if(lis[index+1] > m)break;

		mp[lis[index]]=mn;

		ans += mn;
		chose += lis[index] * mn;
		index+=1;
		// cout<<ans<<' '<<chose<<endl;
	}
	index--;

	while(chose - lis[index] + lis[index+1] <= m){
		chose = chose - lis[index] + lis[index+1];
		index++;
	}
	cout<<ans<<' '<<chose<<endl;

}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>m;

	for(ll i=1;i<=1e5+1;i++){
		lis.push_back(i*i*i);
		// cout<<i*i*i<<endl;
	}


	for(ll i=1e14;i<1e14+1000000;i++){
		print(i);
	}
	cout<<mx<<endl;

// FAKER2
	ll chose=0;
	ll index=0;
	ll pro=1;
	ll ans=0;
	while(chose < m){
		// cout<<"___"<<endl;
		ll mn = min((lis[index+1]-max(chose,1ll))/lis[index] , (m-chose)/lis[index]);
		if(min((lis[index+1]-max(chose,1ll))/lis[index] , (m-chose)/lis[index]) == 0)break;

		mp[lis[index]]=mn;

		ans += min((lis[index+1]-max(chose,1ll))/lis[index] , (m-chose)/lis[index]);
		chose += lis[index] * min((lis[index+1]-max(chose,1ll))/lis[index] , (m-chose)/lis[index]);
		index+=1;
		// cout<<ans<<' '<<chose<<endl;
	}
	index--;

	while(chose - lis[index] + lis[index+1] <= m){
		chose = chose - lis[index] + lis[index+1];
		index++;
	}
	cout<<ans<<' '<<chose<<endl;


// FAKER1
// lis.push_back((ll)1e18);
//
// ll tr = 0;
// ll ans = 0;
// while(tr<m){
// 	auto c = lower_bound(lis.begin(),lis.end(),(m-tr));
// 	if(*c > (m-tr))c--;
//
// 	ll mn = (m-tr)/(*c);
// 	if(mn == 0)break;
//
// 	ans+= mn;
// 	tr += mn*(*c);
// 	cout<<ans<<' '<<tr<<endl;
// }
// cout<<ans<<endl;
	return 0;
}
