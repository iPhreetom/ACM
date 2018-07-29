// CF 1004A
// 	一句话描述：
// 		贪心+验证
// 	总结：
// 		去点时，要判断是否取了同一个点
// 		整数做除法时，要考虑是否可以 去除小数，否则试图转换乘法
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n;ll d;
	cin>>n>>d;

	ll a[105];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	ll ans = 0;
	for(int i=0;i<n;i++){
		if(i == 0){
			ans++;
		}
		else{
			if((a[i]-d) - a[i-1] >= d && (a[i]-a[i-1]) != 2*d)ans++;
		}

		if(i == n-1){
			ans++;
		}
		else{
			if(a[i+1] - (a[i]+d) >= d )ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
