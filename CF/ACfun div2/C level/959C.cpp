// CF 959C worng algorithm
// 	一句话描述：
// 		构造解 + 思维（英语级别的水题）
// 	知识点：
// 		无
// 	总结：
// 		不能因为题目去翻题解
// 		多看几遍，总结归纳，总是能够看懂的


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	if(n<6){
		cout<<-1<<endl;
		// AC
		for(int i=2;i<=n;i++){
			cout<<1<<' '<<i<<'\n';
		}
	}
	else{
		// WA
		for(int i=2;i<=n/2+1;i++){
			cout<<1<<' '<<i<<'\n';
		}
		for(int i=n/2+2;i<=n;i++){
			cout<<2<<' '<<i<<'\n';
		}


		// AC
		for(int i=2;i<=n;i++){
			cout<<1<<' '<<i<<'\n';
		}
	}
	return 0;
}
