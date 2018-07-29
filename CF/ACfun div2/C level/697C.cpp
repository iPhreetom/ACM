#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
map<pair<ll,ll>,ll > mp;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	ll u,v,w,m;
	while(n--){
		cin>>m;
		if(m == 1){
			cin>>u>>v>>w;
			while(u != v){
				if(u > v){
					// mp[{u/2,u}]+=w;
					// if(mp.count(make_pair(u/2,u)) == 0)mp[make_pair(u/2,u)]=0;
					mp[make_pair(u/2,u)]+=w;
					// cout<<mp[make_pair(u/2,u)]<<endl;
					u/=2;
				}
				else{
					// if(mp.count(make_pair(v/2,v)) == 0)mp[make_pair(v/2,v)]=0;
					mp[make_pair(v/2,v)]+=w;
					// cout<<mp[make_pair(v/2,v)]<<endl;
					v/=2;
				}
			}
		}
		else{
			cin>>u>>v;
			ll ans=0;
			while(u != v){
				if(u > v){
					// ans += mp[{u/2,u}];
					ans += mp[make_pair(u/2,u)];
					u/=2;
				}
				else{
					// ans += mp[{v/2,v}];
					ans += mp[make_pair(v/2,v)];
					v/=2;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
