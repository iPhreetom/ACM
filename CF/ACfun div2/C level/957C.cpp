// 957C three level
// 	一句话描述：
// 		二分查找的STL运用
// 	知识点：
// 		STL的二分查找：
// 			返回一个插入后不会改变数列大小性质的位置
// 			插入后，原来元素右移（特判相等）
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll n;
double u;
vector<pair<double,int> > a;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>u;
	// ll index = 0;
	for(int i=0;i<n;i++){
		double t;
		cin>>t;
		a.push_back(make_pair(t,i));
		// cout<<a[i]<<endl;
		// if(a[i].first <= a[0].first+u)index++;
	}

	double ans = 0;
	bool ok = 0;
	// printf("%.10lf\n",(a[index]-a[2])/(a[index]-a[1]));
	int len = a.size();
	for(int i=0;i<len-2;i++){
		// auto t = lower_bound(a,a+n,a[i]+u);
		auto t = upper_bound(a.begin(),a.end(),make_pair(a[i].first+u,0));
		// while(t->first > a[i].first+u)t--;
		// cout<<i<<' '<<t->first<<"   "<<(t->first - a[i+1].first)/(t->first -a[i].first)<<endl;

		if(t->first != a[i].first+u)t--;


		if(t->second < a[i].second + 2)continue;
		else ok = 1;

		// 特判结尾
		// if((t-1)->first != a[i].first+u && t == a.end())continue;
		// else if ((t-1)->first == a[i].first+u)--t;

		// if(t - &a[i] < 2)continue;
		ans = max(ans,(t->first - a[i+1].first)/(t->first-a[i].first));
	}
	if(ok)printf("%.10lf\n",ans);
	else cout<<-1<<endl;

	// cout<<index<<endl;
	// if(index <= 2){
	// 	cout<<-1<<endl;
	// }
	// else{
	//
	// }

	return 0;
}
