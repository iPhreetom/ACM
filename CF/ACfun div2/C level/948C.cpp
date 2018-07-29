// CF 948C snow and melt
// 	一句话描述：
// 		离线 + 二分查找 + 结束标记
// 	知识点：
// 		查询的问题，首先考虑离线 和 在线 两种处理方式
// 		upper_bound （STL） 插入位置是可以不影响原来序列顺序的位置
// 			可以通过减去开头得到下标
// 		结束标记，是一种删除元素的方法
// 			元素之间没有区别
// 			或者，可以通过res，来保存不同元素的差异
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

// ll a[112345];
ll p[112345];
ll t[112345];
ll pret[112345];

ll cnt = 0;

ll ed[112345];
ll res[112345];


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);


	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}

	for(int i=1;i<=n;i++){
		cin>>t[i];
		pret[i] = pret[i-1]+t[i];
	}


	for(int i=1;i<=n;i++){
		auto index = upper_bound(pret,pret+n+1,p[i]+pret[i-1]);
		res[index-pret] += pret[index-pret] - (p[i]+pret[i-1]);
		ed[index-pret]++;
		// cout<<(*index)<<endl;
		// cout<<index-pret<<endl;
	}

	for(int i=1;i<=n;i++){
		cnt++;
		// cout<<ed[i]<<"  "<<res[i]<<endl;
		cout<<t[i]*cnt - res[i]<<' ';
		cnt -= ed[i];
	}



	return 0;
}
