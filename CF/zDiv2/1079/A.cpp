#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// utensil 餐具(刀叉盘...)
// dish 一道菜
// every dish was served alongside with a new set of
	// kitchen utensils
	// 理解： 每一道菜，在被端上来的时候，都带有一套餐具

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,p;
	cin>>n>>p;
	map<int,int> mp;
	int mx = 0;
	int num = 1;
	for (int i=1; i<=n; i++){
		int t;
		cin>>t;
		mp[t]++;
		mx = max(mx,mp[t]);
		num = (mx-1)/p+1;
	}
	int ans = 0;
	for(auto i:mp){
		ans += p*num - i.second;
	}
	cout<<ans<<endl;
	return 0;
}
