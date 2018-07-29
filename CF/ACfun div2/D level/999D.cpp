// CF 999D remainders
// 	一句话描述：
// 		基于队列的模拟 与贪心
// 	知识点：
// 		没有初值的for循环使用：
// 			在最后，要加上break条件，否则容易出现下标加过头
// 		在试图写多重循环时，注意复杂度的实现
// 			判断是否会在最糟糕的情况下退化成n^2
//
// 			当有两层循环时，第二层循环一般是没有初值的for
// 			而其中，就要注意break条件

#include<bits/stdc++.h>
#include<ctime>
#include<windows.h>


using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

queue<pair<long long,long long> >  s[212345];
long long ans = 0;
vector<pair<long long,long long> > out;

// bool cmp(pair<long long,long long> &a , pair<long long,long long> &b){
// 	return a.second < b.second;
// }

int a[212345];

int main(){
	// DWORD t1,t2;
	// t1 = GetTickCount();
	// freopen("D://d.txt","r",stdin);

	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	long long n,m;


	cin>>n>>m;



	for(long long i=1;i<=n;i++){
		long long t;
		cin>>t;
		s[t%m].push(make_pair(t,i));
	}


	long long index = 0;
	bool first=1;
	bool change=0;

	// if(index == 0)index= i;

	for(long long i=0;i<m;i++){
		if(s[i].size() > n/m){
			// index = i; // t21
			// if(first){
			// 	index = i;
			// 	first = 0;
			// }
			if(!change && i > index)index = i;

			for(;index<=m && s[i].size() > n/m;index++){
				if(index == m){
					index = -1;
					change = 1;
					continue;
				}

				while(s[index].size() < n/m && s[i].size() > n/m){
					auto t = s[i].front();
					t.first += (index-i+m)%m;
					ans += (index-i+m)%m;
					s[index].push(t);
					s[i].pop();
				}

				if(s[i].size() == n/m)break;
			}
		}
	}

	for(long long i=0;i<m;i++){
		for(long long j=0;j<n/m;j++){
			// out.push_back(s[i].front());
			a[s[i].front().second] = s[i].front().first;
			s[i].pop();
		}
	}

	// auto func = [=](){/* code */}
	// sort(out.begin(),out.end(),cmp);


	cout<<ans<<endl;
	for(long long i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}

	// t2 = GetTickCount();
	// cout<<(t2-t1)*1.0/1000<<'s'<<endl;
	return 0;
}
