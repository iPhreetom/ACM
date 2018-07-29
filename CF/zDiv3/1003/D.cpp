// CF 1003 D coins and Quries
// 	一句话描述：
// 		模拟人类解决问题的方案
// 		把大数变成小数的算法
// 	知识点：
// 		想清楚，然后写出简洁的算法。才是做对模拟题的正确方式
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,q;
vector<ll> a1(32);
vector<ll> a2(32);
vector<ll> a3(32);

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		ll t;
		cin>>t;
		ll c=-1;
		while(t){
			c++;
			t>>=1;
		}
		a1[c]++;
	}
	// cout<<a1[0]<<endl;

	// for(auto I:a1)cout<<I<<" ";cout<<endl;
	for(int i=0;i<q;i++){
		a2 = a1;
		fill(a3.begin(),a3.end(),0);
		ll t;
		cin>>t;

		// cout<<"________________"<<endl;
		ll c=0;
		while(t){
			if(t&1){
				a3[c]++;
				// cout<<c<<' ';
			}
			c++;
			t>>=1;
		}
		// cout<<endl;

		bool ok = 1;
		ll ans = 0;
		for(int j=31;j>0;j--){
			// 在
			if(a3[j]){
				if(a2[j]){
					if(a2[j]>=a3[j]){
						a2[j]-=a3[j];
						ans+=a3[j];
						a3[j]=0;
					}
					else{
						a3[j]-=a2[j];
						ans+=a2[j];
						a2[j]=0;

						a3[j-1]+=a3[j]*2;
						a3[j]=0;
					}
				}
				else{
					a3[j-1]+=a3[j]*2;
					a3[j]=0;
				}
			}
		}

		// 特判a3[0]
		if(a2[0] >= a3[0]){
			ans+=a3[0];
			a3[0]=0;
			a2[0]-=a3[0];
		}
		else{
			cout<<"-1"<<endl;
			continue;
		}
		// cout<<"YES"<<endl;
		cout<<ans<<endl;


		// cout<<"========"<<endl;
	}
	return 0;
}
/*
ll sum = pow(2,j);
// cout<<sum<<endl;
for(int k=j;sum>0 && k>=0;k--){
	if(a2[k]){

		// cout<<"K: "<<k<<endl;

		if(sum >= a2[k]*pow(2,k)){
			sum -= a2[k]*pow(2,k);
			ans += a2[k];
			a2[k]=0;
		}
		else{
			int l=0,r=a2[k]+1;
			while(l+1 < r){
				int mid = l+(r-l)/2;
				if(pow(2,k)*mid > sum)r = mid;
				else l = mid;
			}
			if(pow(2,k)*r <= sum){
				sum -= pow(2,k)*r;
				ans += r;
				a2[k]-=r;
			}
			else{
				sum -= pow(2,k)*l;
				ans += l;
				a2[k]-= k;
			}
			// cout<<"LRK "<<l<<' '<<r<<' '<<k<<endl;
		}
	}
}
if(sum > 0){
	ok=0;
}
*/
