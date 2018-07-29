#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	ll past=0;
	ll past2=0;
	ll id;
	ll re=0;
	ll dp;
};
vector<vector<ll> > vec;
ll book[212345];
node arr[212345];
vector<ll> ans;
bool f=0;
bool d=0;
bool zero=0;

void dfs(ll index,ll dp,ll cnt){
	if(f)return ;

	node p = arr[index];
	if(vec[p.id].size()==0 && dp%2==0){
		f = 1;
		// find way
		// 利用一个数组保存每个节点的相关信息
		// 回溯时，利用节点信息的past变量，在数组中移动
		int past = p.past;
		while(past != 0){
			if(p.re == 2){
				ans.push_back(p.id);
				past = p.past2;
				arr[p.id].re--;
				p = arr[p.past2];
			}
			else{
				ans.push_back(p.id);
				past = p.past;
				p = arr[p.past];
			}
		}
	}

	for(int i=0;i<vec[p.id].size();i++){
		if(arr[vec[p.id][i]].re == 0){
			// 记录
			arr[vec[p.id][i]].re = 1;
			arr[vec[p.id][i]].past = p.id;
			arr[vec[p.id][i]].dp = dp;

			dfs(vec[p.id][i],dp+1,p.id);

			// 消除记录
			arr[vec[p.id][i]].re = 0;
			arr[vec[p.id][i]].past = 0;// 其实没关系
		}

		if(arr[vec[p.id][i]].re == 1){
			d=1;
			if(!zero)f=1;
		}

		if(arr[vec[p.id][i]].re == 1 && dp%2 == arr[vec[p.id][i]].dp%2){

			// 记录
			arr[vec[p.id][i]].re = 2;
			arr[vec[p.id][i]].past2 = p.id;

			dfs(vec[p.id][i],dp+1,p.id);

			// 消除记录
			arr[vec[p.id][i]].re = 1;
		}
	}

}

void init(){
	for(int i=0;i<212345;i++){
		arr[i].id = i;
	}
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	init();
	ll n,m;
	cin>>n>>m;

	vec.resize(n+1);
	for(int i=1;i<=n;i++){
		ll t;
		cin>>t;
		for(int j=0;j<t;j++){
			ll to;
			cin>>to;
			vec[i].push_back(to);
		}
	}

	ll be;
	cin>>be;

	// check
	for(int i=0;i<n;i++){
		if(vec[i].size()==0)zero=1;
	}
	dfs(be,1,0);

	if(f){
		if(!zero){
			cout<<"Draw"<<endl;
			return 0;
		}
		cout<<"Win"<<endl;
		for(int i=ans.size()-1;i>=0;i--){
			cout<<ans[i]<<' ';
		}cout<<endl;
	}
	else{
		if(d)cout<<"Draw"<<endl;
		else cout<<"Lose"<<endl;
	}
	return 0;
}
