// 失败的982D题尝试
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll n;
ll a[112345];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;

	ll mx = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mx = max(a[i],mx);
	}

	for(int i=2;;i++){
		if(n<i){
			cout<<mx+1<<endl;
			return 0;
		}
		else{
			if(n&i==0 || (n+1)%i==0 || (n-1)%i==0){
				bool ok = 1;
				ll mc=1e9+9;
				for(int j=0;j<n;j+=i){
					mc=min(mc,a[j]);
				}
				for(int j=0;j<n;j++){
					if(j%i==0)continue;
					else{
						if(a[j] >= mc)ok=0;
					}
				}

				if(ok){
					cout<<mc<<endl;
					// cout<<i<<endl;
					return 0;
				}
				else{
					ok = 1;
					ll mc=1e9+9;
					for(int j=i-1;j<n;j+=i){
						mc=min(mc,a[j]);
					}
					for(int j=0;j<n;j++){
						if((j+1)%i==0)continue;
						else{
							if(a[j] >= mc)ok=0;
						}
					}
					if(ok){
						cout<<mc<<endl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
