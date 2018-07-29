// CF 987C
// 	一句话描述
// 		缩小范围的 动态规划
// 	知识点：
// 		利用map，把数组的每个元素在Nlogn的时间内算出rank
// 		dp的记忆化有两种方式：
// 			数据的元素小的时候，暴力记忆元素
// 			数据的元素大的时候，可以考虑变形，等价rank后，暴力记忆元素
// 			数据规模大的时候，就要考虑前x个y的写法

#include<bits/stdc++.h>
using namespace std;

int dp[3001][3001][4];
long long  n;
long long  a[312345];
vector<pair<long long,long long>> arr;
map<long long , long long> m;
long long  c[312345];
set<long long> se;
// pair<pair<int,int>,int>

long long dpf(long long  index,long long len,long long  num){

	if(dp[index][num][len] != -1)return dp[index][num][len];
	if(len == 3)return dp[index][num][len]=0;
	if(index >= n)return dp[index][num][len]=2e9;

	if(a[index] > num){
		dp[index][num][len] = min(dpf(index+1,len+1,a[index])+c[index],dpf(index+1,len,num));
	}
	else dp[index][num][len] = dpf(index+1,len,num);

	return dp[index][num][len];
}




int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(dp,-1,sizeof(dp));


	cin>>n;
	for(long long  i=0;i<n;i++){
		cin>>a[i];
		arr.push_back(make_pair(a[i],0));
	}



	sort(arr.begin(),arr.end());


	int rank = 1;
	arr[0].second=1;
	m.insert(make_pair(arr[0].first,arr[0].second));

	for(int i=1;i<arr.size();i++){
		if(arr[i].first == arr[i-1].first){
			arr[i].second = rank;
			m.insert(make_pair(arr[i].first,arr[i].second));
		}
		else{
			arr[i].second = ++rank;
			m.insert(make_pair(arr[i].first,arr[i].second));
		}
	}

	for(int i=0;i<n;i++){
		a[i] = m[a[i]];
		// cout<<a[i]<<endl;
	}

	for(long long  i=0;i<n;i++){
		cin>>c[i];
	}
	long long ans = dpf(0,0,0);
	if(ans == 2e9){
		cout<<-1<<endl;
	}
	else{
		cout<<ans<<endl;
	}

	// 6
	//
	return 0;
}
