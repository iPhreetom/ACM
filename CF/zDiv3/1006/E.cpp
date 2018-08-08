#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int n,q;
vector<vector<int> > a(212345);
int pre[212345];
int dp[212345];
int son[212345];
bool findit = 0;

void dfs(int u,int &k){
	k++;
	pre[u]=k;
	dp[k]=u;

	for(int i=0;i<a[u].size();i++){
		dfs(a[u][i],k);
	}
}

int bfs(int u){
	son[u] = 1;

	if(a[u].size()==0){
		return son[u];
	}

	int sum = 0;
	for(int i=0;i<a[u].size();i++){
		sum += bfs(a[u][i]);
	}

	return son[u] += sum;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int t;
		cin>>t;
		a[t].push_back(i);
	}

	int tp=0;
	dfs(1,tp);
	bfs(1);
	for(int i=0;i<q;i++){
		int u,k;
		cin>>u>>k;
		if(son[u] >= k){
			cout<<dp[pre[u]+k-1]<<' ';
		}
		else{
			cout<<-1<<' ';
		}
	}
	cout<<endl;
	return 0;
}
