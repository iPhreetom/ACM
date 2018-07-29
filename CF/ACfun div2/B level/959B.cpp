
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<pair<pair<string,ll>,ll> > a(112345);
map<string,ll> mc;
map<string,ll> mgc;
ll g[112345];
ll n,k,m;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	fill(g,g+112345,1e9+7);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].first.first;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].first.second;
		// mc[a[i].first.first]=a[i].first.second;
	}
	// cout<<"group"<<endl;
	for(int i=1;i<=k;i++){
		ll t;
		cin>>t;
		vector<ll> lis;
		for(int j=0;j<t;j++){
			ll index;
			cin>>index;
			lis.push_back(index);
			g[i] = min(g[i],a[index].first.second);
		}

		for(int j=0;j<lis.size();j++){
			// cout<<"a lis:"<<a[lis[j]].first.first<<" --- >>  ";
			// cout<<g[i]<<endl;
			mgc[a[lis[j]].first.first]=g[i];
		}
	}
	// cout<<"____"<<endl;

	ll ans = 0;
	for(int i=0;i<m;i++){
		string a;
		cin>>a;
		// cout<<a<<' '<<mgc[a]<<endl;
		ans += mgc[a];
	}
	cout<<ans<<endl;

	return 0;
}
