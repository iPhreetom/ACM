#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

priority_queue<int,vector<int>,greater<int>> que;
vector<int> mp[800];
int n;

void dfs(int i,int j,int sum){
	sum += mp[i][j];

	if(i == n-1){
		que.push(sum);
		return ;
	}

	dfs(i+1,1,sum);
	dfs(i+1,0,sum);
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	while(cin>>n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int t;
				cin>>t;
				mp[i].push_back(t);
			}
		}

		for(int i=0;i<n;i++){
			sort(mp[i].begin(),mp[i].end());
		}

		while(!que.empty())que.pop();
		dfs(0,0,0);
		dfs(0,1,0);

		for(int i=0;i<n;i++){
			if(i!=n-1)cout<<que.top()<<' ';
			else cout<<que.top()<<endl;
			que.pop();
		}
	}
	return 0;
}
