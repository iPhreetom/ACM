// CF 1004C robots
// 	一句话描述：
// 		模拟+后缀的情况数
// 	总结：
// 		不同的数的组合，似乎可以用组合数学的方法
// 		但是实际上，直接模拟每一个元素的匹配数会更加简单
// 			数学 与 模拟-暴力 的界限不明显
// 		感觉是数学题的时候，如果觉得复杂，试试打表、模拟的做法

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// bool bookpre[112345];
// bool booksuf[112345];
// ll countsuf[112345];
// ll countpre[112345];
ll a[112345];
bool book[112345];
ll bookcnt[112345];
ll cntsuf[112345];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}

	if(n == 1){
		cout<<0<<endl;
		return 0;
	}

	// cout<<"+++++"<<endl;
	for(ll i=n-1;i>=1;i--){
		if(bookcnt[a[i]]==0){
			bookcnt[a[i]]=1;
			cntsuf[i]++;
		}
		cntsuf[i] += cntsuf[i+1];
		// cout<<cntsuf[i]<<' ';
	}
	// cout<<endl;

	ll ans = 0;
	for(ll i=0;i<n-1;i++){
		if(book[a[i]] == 0){
			book[a[i]]=1;
			ans += cntsuf[i+1];
			// cout<<cntsuf[i+1]<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
