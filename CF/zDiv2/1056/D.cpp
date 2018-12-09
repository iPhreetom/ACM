// 只关心叶子节点个数的DFS题目
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> mp[212345];
int a[212345];
int sum[212345];
bool vis[212345];

int dfs(int p){
	vis[p] = 1;
	a[p] = 0;
	int cnt = 0;
	for (int i=0; i<mp[p].size(); i++){
		if(!vis[mp[p][i]]){
			cnt++;
			a[p] += dfs(mp[p][i]);
		}
	}
	if(cnt == 0){
		a[p] = 1;
	}
	return a[p];
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1; i<=n-1; i++){
		int v;
		cin>>v;
		mp[v].push_back(i+1);
		mp[i+1].push_back(v);
	}
	dfs(1);
	for (int i=1; i<=n; i++){
		// cout<<"a[i] = "<<a[i]<<endl;
		sum[a[i]]++;
	}
	for (int i=1; i<=n; i++){
		sum[i] += sum[i-1];
	}
	int index = 1;
	for (int i=1; i<=n; i++){
		if(sum[index] >= i){
			cout<<index<<endl;
		}
		else{
			while(sum[index] < i)index++;
			cout<<index<<endl;
		}
	}
	// 模拟一下：
	// 如果最下
	return 0;
}
