// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int n,m;
vector<priority_queue<int,vector<int>,greater<int> > > a(3123);
vector<pair<int,int> > arr;
int ans ;
int index;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=0; i<n; i++){
		int q,w;
		cin>>q>>w;
		a[q].push(w);
		if(q != 1){
			arr.push_back(make_pair(w,q));
		}
	}
	int h1 = a[1].size();
	while(!a[1].empty())a[1].pop();
	sort(arr.begin(),arr.end());

	while(1){
		int mx = 0;
		int num = 0;
		int sum = 0;
		priority_queue<int,vector<int>,greater<int> > que;
		// vector<pair<int,int> >  tmp;

		for (int i=1; i<=n; i++){
			mx = max(mx,(int)a[i].size());
		}

		// 特判结束点
		if(h1 > mx){
			cout<<ans<<endl;
			break;
		}
		if(h1 == mx){
			ans += arr[index++].first;
			cout<<ans<<endl;
			break;
		}

		// 找到最高点个数
		for (int i=1; i<=n; i++){
			if(a[i].size() == mx){
				num++;
				sum += a[i].top();
			}
		}


		if(num > mx-h1){
			// 直接暴力得到答案
			while(h1 <= mx){
				ans += arr[index++].first;
				h1++;
			}
			cout<<ans<<endl;
			break;
		}
		else {
			// 否则，询问 选取所有点大 还是 前N+1个大

		}


		if(mx >= h1){

		}
		else{
			cout<<ans<<endl;
			break;
		}
	}
	return 0;
}
