// 知识点：
	// 子联通图的问题
		// 联通的性质（包含的联通个数
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<vector<ll> > a(112345);
vector<ll> ct(112345);
bool vis[112345];
ll ans;


int bfs(int id){
	vis[id]=1;
	ct[id]=1;
	for(int i=0;i<a[id].size();i++){
		if(!vis[a[id][i]]){
			// vis[a[id][i]]=1;
			ct[id]+=bfs(a[id][i]);
		}
	}
	return ct[id];
}


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	if(n%2==1){cout<<-1<<endl;return 0;}
	for(int i=0;i<n-1;i++){
		int v,u;
		cin>>v>>u;
		a[v].push_back(u);
		a[u].push_back(v);
	}
	bfs(1);
	for(int i=1;i<=n;i++){
		// cout<<ct[i]<<endl;
		if(ct[i] != 0 && ct[i]%2==0){
			ans++;
		}
	}
	cout<<--ans<<endl;
	return 0;
}
