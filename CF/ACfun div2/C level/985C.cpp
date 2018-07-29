// CF 985C Barrels and stave
// 贪心与证明
// 知识点：
// 	写贪心： 写完不能交，先HACK一波（贪心题不能想着抢一血）
// 	证明贪心，可以考虑在发现BUG后写一组样例，分别给源程序跑，和改好的跑
#include<bits/stdc++.h>
using namespace std;


long long n,k,l;
long long a[212345];
long long ans = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>k>>l;
	for(int i=0;i<n*k;i++){
		cin>>a[i];
	}
	sort(a,a+n*k);
	// 小的放前面
	long long mn = a[0];
	long long index = upper_bound(a,a+n*k,mn+l)-a-1;
	// 如果
	// 1 2 3 4 5 6
	// 我取 3 2 3
	// index = 3
	// 略过2 ，取得1 3 4
	// ok

	// 如果全部相等
	// 2 2 2 2 2 2
	// 我去 3 2 1
	// 那么返回index = 5
	// 略过 index-n+1 == res
	// res == 3
	// 策略不对

	//如果第一个木桶不能把res中的木板容下，那就就贪心失败
	// 证明完了

	// 正确思路：（在错误中探寻真理）
		// 增加一个判断，是否能继续在最短木桶中加木块
//data:
	// 3 2 4
	// 1 2 3 4 4 4
	if(index+1 < n)cout<<0<<endl;
	else{
		long long res = index-n+1;
		// cout<<res<<endl;
		ans = a[0];
		long long count =  1;
		for(int i=1;i<=index;i++){
			if(res && count != k){
				res--;
				count++;
			}
			else{
				ans += a[i];
				count = 1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
