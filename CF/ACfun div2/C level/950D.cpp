// CF 950D leapfrog adn array
// 	一句话描述：
// 		模拟 + 之差一步的数学题
// 	知识点：
// 		通过从前向后模拟，找到数字的规律（则中题目怎么可能是D题）
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n,p;
	cin>>n>>p;
	ll t;
	for(int i=0;i<p;i++){
		cin>>t;
		while(t%2==0){
			t += (n-t/2);
		}
		cout<<t/2+1<<endl;
	}
	return 0;
}
