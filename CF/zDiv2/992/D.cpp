#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
ll a[212345];
ll book[212345];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=0;i--){
		book[i] = book[i+1];
		if(a[i] == 1){
			book[i]++;
		}
	}

	ll l=0,r=0;
	ll b=0;
	ll s=0,p=1;
	ll ss,sp;
	ll ans = 0;
	bool again = 0;

	do{
		for(int i=b,;i<n;i++){
			s+=a[i];	p*=a[i];
			// cout<<i<<endl;
			/// p/s = k
			if(p < k*s){
				continue;
			}
			if(p == k*s){
				ans++;
				continue;
			}
			if(p > k*s){
				if(p-k*s <= book[i]){
					again = 1;
					b = i+1;
				}
				else{
					if(again)break;
					// 向前减
					else{
						while(p > k*s){
							p/=a[l];
							s-=a[l++];
							if(p-k*s <= book[i]){
								again = 1;
								b = i+1;
								break;
							}
						}
					}
				}
			}
		}
	}while(again);
	cout<<ans<<endl;
	return 0;
}
