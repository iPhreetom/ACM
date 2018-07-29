// CF 962D Merge Equals
// 	一句话描述：
// 		优先队列处理，顺序不断变化的数组。
// 	知识点：
// 		拼写：priority_queue
// 		比较函数写法(在定义时使用):
// 			struct cmp { bool operator() (pll a , pll b){和vector相反的写法} };
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;

typedef pair<ll,ll> ll2;

// bool cmp2(pair<ll,ll> a, pair<ll,ll> b){
// 	return a.second < b.second;
// }

struct cmp1{
    bool operator() ( ll2 a, ll2 b ){
		return a.first!=b.first?a.first>b.first : a.second > b.second;
	}
};

struct cmp2{
    bool operator() ( ll2 a, ll2 b ){return a.second > b.second;}
};

priority_queue<pair<ll,ll>,vector<ll2>,cmp1 > que;
priority_queue<ll2,vector<ll2>,cmp2 > ans;



int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	ll t1,t2;
	for(int i=1;i<=n;i++){
		cin>>t1;
		que.push(make_pair(t1,i));
	}


	while(que.size()>1){
		pair<ll,ll> t = que.top();
		que.pop();
		if(que.top().first == t.first){
			t = que.top();
			que.pop();
			t.first*=2;
			que.push(t);
		}
		else{
			ans.push(t);
		}
	}
	if(!que.empty())ans.push(que.top());
	cout<<ans.size()<<endl;
	while(!ans.empty()){
		cout<<ans.top().first<<' ';
		ans.pop();
	}

	return 0;
}
