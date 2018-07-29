// CF 948C snow and melt
// 	一句话描述：
// 		在线 + 使用优先队列把n^2 -> nlogn
// 	知识点：
// 		优先队列的线性遍历，在有删除的情况下，也是lgn
// 	总结：
// 		首先可以考虑出最暴力的做法（会TLE
// 		然后考虑使用数据结构优化其中的一个系数
// 			一般来说，查询是N,获得查询结果的方法是lgn


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


priority_queue<ll,vector<ll>,greater<ll> > que;
ll t[112345];
ll pret[112345];
ll m[112345];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
		pret[i] = pret[i-1]+t[i];
		m[i]+=pret[i-1];
		que.push(m[i]);

		ll res = 0;
		while(!que.empty() && que.top() < pret[i]){
			res += que.top()-pret[i-1];
			que.pop();
		}
		cout<<que.size()*t[i] + res<<' ';
	}
	return 0;
}
