// CF 985A 送命模拟
	// 一句话描述：
		// 用最暴力的方法，模拟移动棋子
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll a[100];
ll b[100];

ll a1,a2;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n/2;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n/2);
	sort(b,b+n/2);

	ll ans = 0;
	for(int k=0;k<1000;k++){
		for(int i=0;i<n/2;i++){
			if(a[i] < (i*2+1)){
				while(a[i] < (i*2+1) && a[i+1] != a[i]+1){
					a[i]++;
					a1++;
				}
			}
			else{
				while(a[i] > (i*2+1) && a[i-1] != a[i]-1){
					a[i]--;
					a1++;
				}
			}
		}
	}
	for(int i=0;i<n/2;i++){
		if(a[i]!=(i*2+1))a1=1e9;
	}

	for(int k=0;k<1000;k++){
		for(int i=0;i<n/2;i++){
			if(b[i] < (i+1)*2){
				while(b[i] < (i+1)*2 && b[i+1] != b[i]+1){
					b[i]++;
					a2++;
				}
			}
			else{
				while(b[i] > (i+1)*2 && b[i-1] != b[i]-1){
					b[i]--;
					a2++;
				}
			}
		}
	}
	for(int i=0;i<n/2;i++){
		if(b[i]!=(i+1)*2)a2=1e9;
	}


	cout<<min(a1,a2)<<endl;
	return 0;
}
