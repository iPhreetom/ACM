// CF 988C Equal sum
// 	一句话描述：
// 		map记录位置 + 在线求答案
// 	知识点：
// 		用 key 保存值 ， 顺带lgn查找(count)
// 		用map + pair<> 记录第几行，第几列

#include<bits/stdc++.h>
using namespace std;

map<int,pair<int,int>> m;

int a[(int)2e5+1];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int k,sum=0;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[j];
			sum+=a[j];
		}

		for(int j=0;j<k;j++){
			if(m.count(sum-a[j]) != 0){
				cout<<"YES"<<endl;
				cout<<m[sum-a[j]].first +1<<' '<<m[sum-a[j]].second+1<<endl;
				cout<<i+1<<' '<<j+1<<endl;
				return 0;
			}
		}

		for(int j=0;j<k;j++){
			m.insert(make_pair(sum-a[j],make_pair(i,j)));
		}

	}
	cout<<"NO"<<endl;


	return 0;
}
