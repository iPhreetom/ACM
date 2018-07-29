// CF 1008C
// 	一句话描述：
// 		模拟解决数学问题
// 	总结：
// 		依照题意模拟，依照题意写出最复杂的算法
// 		然后再考虑优化的事情
#include<bits/stdc++.h>
#define int long long
using namespace std;


vector<int> a;
vector<int> b;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	cin>>n;

	int t;
	for(int i=0;i<n;i++){
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	b = a;

	int index = n-1;
	int ans = 0;
	for(int i=n-1;i>=0;i--){
		while(index >= 0){
			if(a[i] > b[index]){
				ans++;
				index--;
				break;
			}
			else{
				index--;
			}
		}
		if(index == -1)break;
	}
	cout<<ans<<endl;

	return 0;
}
