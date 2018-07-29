// CF 996 leaving the bar
// 	一句话描述：
// 		贪心与几何，题解是巧妙的 贪心随记算法
// 	知识点：
// 		当贪心有可能失败时
// 			通过随机化，多次贪心，试图得到正解
// 		这个思路和【多次迭代找近似解】相似

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

// vector<int> ans;
int ans[212345];
vector<pair<pair<ll,ll>,ll> > vec;

bool cmp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
	return pow(a.first.first,2) + pow(a.first.second,2) > pow(b.first.first,2) + pow(b.first.second,2);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	ll n;
	cin>>n;

	for(int i=0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		vec.push_back(make_pair(make_pair(a,b),i));
	}
	// sort(vec.begin(),vec.end(),cmp);

	while(1){
		ll num = 0,x=0,y=0;
		for(int i=0;i<n;i++){
			if( (x+vec[i].first.first)*(x+vec[i].first.first)+(y+vec[i].first.second)*(y+vec[i].first.second) > (x-vec[i].first.first)*(x-vec[i].first.first)+(y-vec[i].first.second)*(y-vec[i].first.second) ){
				x -= vec[i].first.first;
				y -= vec[i].first.second;
				ans[vec[i].second]=-1;
			}
			else{
				x += vec[i].first.first;
				y += vec[i].first.second;
				ans[vec[i].second]=1;
			}
		}

		if(x*x + y*y <= 225e10){
			break;
		}
		else{
			random_shuffle(vec.begin(),vec.end());
		}
	}


	for(int i=0;i<n;i++){
		cout<<ans[i]<<' ';
	}


	return 0;
}
