// CF 965C greedy
// 	一句话描述：
// 		暴力枚举
// 	知识点：
// 		数据范围与边界条件。
// 		关注乘法是否会超出long long范围
// 		关注是否最小枚举点过大


#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,k,m,d;
	cin>>n>>k>>m>>d;

	long long x=m;
	long long sum=0;
	long long mn;
	long long ans = 0;


	for(int i=1;i<=d;i++){//BUG1
		// cout<<"???"<<endl;
		if((long long)(2e18)/k < i){
			break;//BUG2
		}
		x = min(m,n/((i-1)*k+1));
		sum = max(sum,i*x);
	}
	cout<<sum<<endl;

	return 0;
}
