// 957D riverside
// 	一句话描述：
// 		模拟处理
// 	知识点：
// 		一次只能改变有限大小的序列
// 			何如选取每个位置最大值的问题
// 			通过前缀数组得到前缀最大值
// 			而后，从后向前，保证连续性
// 	总结：
// 		模拟与贪心，我一开始的策略是错误的，并且自己没有发觉
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll tt=1;
ll a[312345];
ll mx[312345];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n;
	ll ans = 0;
	cin>>n;
	mx[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx[i] = max(mx[i-1],a[i]+1);
		// cout<<mx[i]<<endl;
	}
	// cout<<endl;
	for(int i=n-1;i>=0;i--){
		// ans += mx[i]-a[i]-1;
		if(mx[i] != mx[i+1]){
			mx[i] = mx[i+1]-1;
		}
		// cout<<ans<<endl;
	}
	for(int i=n;i>=1;i--){
		ans += mx[i]-a[i]-1;
		// cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
