// CF 526B Dark path
// 一句话描述：
// 	数据结构（基于数组的树）+ 贪心策略
// 知识点：
// 	基于数组的树必须是 满二叉树
// 		父亲节点是 i/2
// 		儿子节点是 i + 2^i 与 i + 2^i +1
// 	在边不再点：
// 		强行假设一个新的根，把边看作点处理
#include<bits/stdc++.h>
using namespace std;

long long a[1<<10 + 2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=(1<<n+1)-2;i++){
		cin>>a[i];
	}

	for(int i=(1<<n+1)-2;i>=1;i-=2){
		ans += abs(a[i-1]-a[i]);
		a[(i-1)/2] += max(a[i-1],a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
