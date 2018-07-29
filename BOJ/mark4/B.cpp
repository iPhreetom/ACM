// CF 788A Function
 	// 一句话描述：
		// 基于贪心的策略选择

#include<bits/stdc++.h>
using namespace std;

long long fix1[112345];
long long fix2[112345];
long long a[112345];
long long n;
long long  odd=1,even=1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(i>0){
			if(odd==1){
				fix1[i-1] = abs(a[i-1]-a[i]) *1;
				odd = -1;
			}
			else{
				fix1[i-1] = abs(a[i-1]-a[i]) *-1;
				// cout<<fix1[i-1]<<endl;
				odd = 1;
			}
			if(i>1){
				// fix1[i-1] += fix1[i-2];

				if(even==1){
					fix2[i-1] = abs(a[i-1]-a[i])*1;
					even = -1;
				}
				else{
					fix2[i-1] = abs(a[i-1]-a[i])*-1;
					even = 1;
				}

				// fix2[i-1]+=fix2[i-2];
			}
		}
	}
	long long ans = 0;
	long long ans1;
	long long ans2;
	odd = 1;
	for(long long i=0;i<n-1;i++){
		ans += fix1[i];
		if(ans<0)ans=0;
		ans1 = max(ans1,ans);
	}

	ans = 0;
	for(long long i=1;i<n-1;i++){
		ans += fix2[i];
		if(ans<0)ans=0;
		ans1 = max(ans1,ans);
	}
	cout<<ans1<<endl;

	// cout<<"Fix1"<<endl;
	// for(long long i=0;i<n;i++){
	// 	cout<<fix1[i]<<" ";
	// }
	//
	//
	// cout<<"\nFix2"<<endl;
	// for(long long i=0;i<n;i++){
	// 	cout<<fix2[i]<<" ";
	// }
	return 0;
}
