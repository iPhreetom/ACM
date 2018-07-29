#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	ll x,y,r,l;
	cin>>l>>r>>x>>y;

	set<ll> a,b,c;

	// 特判相等
	if(x == y){
		if(x>r || x<l){
			cout<<0<<endl;
			return 0;
		}
		cout<<1<<endl;
		return 0;
	}

	// 特判取不到值
	if( x * y < l*l){
		cout<<0<<endl;
		return 0;
	}
	if( x*y > r*r){
		cout<<0<<endl;
		return 0;
	}

	ll t;
	t = sqrt(x);
	for(int i=1;i<=t+1;i++){
		if(x % i == 0){
			a.insert(i);
			a.insert(x/i);
		}
	}

	t = sqrt(y);
	for(int i=1;i<=t+1;i++){
		if(y % i == 0){
			b.insert(i);
			b.insert(y/i);
		}
	}

	for(auto i : a){
		for(auto j : b){
			c.insert(i*j);
		}
	}

 	ll ans = 0;
	for(auto i:c){
		// cout<<i<<endl;
		if(l<=i && i<=r && l<=(x*y/i) && (x*y/i)<=r){
			if(__gcd(i,(x*y/i)) == x){
				// if(i != x*y/i)ans+=2;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
