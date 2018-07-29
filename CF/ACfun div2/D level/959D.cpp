// CF 959D Aarry construction task
// 	一句话描述：
// 		使用素数表 + 约数标记  构造数列
// 	知识点：
// 		使用 打表生成素数时。在记住在最后遍历 bool数组。把是素数的添加
// 			否则，我们只拥有sqrt(n)内的素数
// 		使用 约数标记
// 			可以判断现有的数列元素是否互质：
// 			复杂度是n/-n
// 	总结：
// 		WA8:
// 		在修改之后，把素数表打错了导致wa
// 		处理的方法：如果没有错误信息，当然是重新看一遍代码，通过写伪代码的形式，DEBUG
//
// 		WA17:
// 		在insert函数中，应该要添加约数。这个逻辑漏洞，要么看代码。要么面相样例。

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const int mx = 1e7;
bool pr[mx];
vector<int> pri;
set<int> ys;
bool same= 1;
vector<int> ans;

void init(){
	int gen = sqrt(mx);
	// memset(pr,1,sizeof(pr));
	fill(pr,pr+mx,1);
	for(int i=2;i<=gen;i++){
		if(pr[i]){
			// pri.insert(make_pair(pr[i],1));
			// pri.push_back(i);
			for(int j=i+i;j<mx;j+=i){
				pr[j]=0;
			}
		}
	}
	for(int i=2;i<mx;i++){
		if(pr[i])pri.push_back(i);
	}
}

bool check(int t){
	if(ys.count(t) != 0)return 0;
	for(int i=2;i<=sqrt(t);i++){
		if(t%i == 0){
			if(ys.count(i)!=0 || ys.count(t/i)!=0)return 0;
		}
	}
	return 1;
}

void find(int t){
	ys.insert(t);
	for(int i=2;i<=sqrt(t);i++){
		if(t%i == 0){
			ys.insert(t/i);
			ys.insert(i);
		}
	}
}

void insert(int t){
	// 插入一个比t大的数
	// auto index = upper_bound(pri.begin(),pri.begin()+pri.size(),t);
	// if(ys.count(*index) != 0){
	// 	for(auto i=index+1;i!=pri.end();i++){
	// 		if(ys.count(*i) == 0){
	// 			ys.insert(*i);
	// 			cout<<*i<<' ';
	// 			return ;
	// 		}
	// 	}
	// }
	same = 0;
	for(int i=t+1;i<mx;i++){
		if(check(i)){
			find(i);
			// cout<<i<<' ';
			ans.push_back(i);
			return ;
		}
	}
	//
	// ys.insert(*index);
	// cout<<*index<<' ';
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// init();
	int n;
	init();
	// cout<<pri.size()<<endl;
	int index= 0;


	cin>>n;
	int t;
	for(int i=0;i<n;i++){
		cin>>t;
		if(same){
			if(check(t)){
				find(t);
				// cout<<t<<' ';
				ans.push_back(t);
			}
			else insert(t);
		}
		else{
			for(;index<pri.size();index++){
				if(ys.count(pri[index])==0){
					ys.insert(pri[index]);
					// cout<<pri[index]<<' ';
					ans.push_back(pri[index]);
					index++;
					break;
				}
			}
		}
	}
	// cout<<'\n'
	if(ans.size()!=n){
		cout<<ans.size()<<endl;
	}
	else{
		for(int i=0;i<ans.size();i++){
			if(i==0){
				cout<<ans[i];
			}
			else{
				cout<<' '<<ans[i];
			}
		}
		cout<<endl;
	}


	return 0;
}
