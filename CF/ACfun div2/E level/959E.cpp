// CF 959E MST and XOR
	// 一句话描述：
	// 	最小生成树的加点思路 与 二进制数 操作方法，与抑或性质
	// 知识点：
	//  	最小生成树加点思路：（基于贪心）
	// 		假设向 已经联通的区域 再加一个点
	// 			这个点的选择就可以通过 贪心取得（可能二分查找优化）
	// 	二进制数操作方法：
	// 		一般而言，通过不断>>1，的位移操作得到答案是常规方法。
	// 		遇到1的时候，出现特殊情况（易于计算）
	// 	抑或性质：
	// 		一般性质：
	// 			任何数抑或0，值不会改变
	// 			结合律和交换律都满足
	// 			==>  数X的自反性：
	// 				X XOR X == 0
	// 				X XOR Y XOR X == Y
	//
	// 				这个性质可以判断奇数次出现的数，和偶数次出现的数。
	// 		此题结论：
	// 			一个数K，和比它小的任意整数XOR（包含0），可以得到一个有序的序列，然后找规律(递归处理
	// 				递归处理：通过判断1的个数（n/2）,2的个数(n/4)....




#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n;
	cin>>n;
	n--;

	ll high=0;
	// ll val=1;
	// while(val*2 <= n){
	// 	val*=2;
	// 	high++;
	// }

	ll ans = 0;
	while(n > 0){
		if(n%2==1){
			ll t = pow(2,high);
			ll t2 = 1;
			ans += t;
			while(t>0){
				ans += (t/2)*t2;
				t2*=2;
				t/=2;
			}
		}
		n>>=1;
		high++;
	}
	cout<<ans<<endl;
	return 0;
}
