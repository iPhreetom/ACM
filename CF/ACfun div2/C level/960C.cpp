// CF 960C subsequence counting
// 	一句话描述：
// 		构造解
// 	知识点：
// 		构造的定义：
// 			生成满足某种条件的数据
// 			生成解的时候，尽量向简单的方向考虑（如何能够更简单的生成）
// 	总结：
// 		没做出来的原因：
// 			没能够看懂题意，把子串的形式认为是不同的元素的组合。推断出【此题不会做】
// 		得出小结论：只是【子串】作为条件，那么可以考虑元素相同
#include<bits/stdc++.h>
#define f(a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


vector<long long> ans;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	long long x,d;
	cin>>x>>d;
	long long len=0,num=d;
	while(x > 0){
		if(x&1){
			f(0,len)ans.push_back(num);
			num+=d;
			ans.push_back(num);
			num+=d;
		}
		x>>=1;
		len++;
	}
	cout<<ans.size()<<endl;
	for(auto I:ans)cout<<I<<' ';
	return 0;
}
