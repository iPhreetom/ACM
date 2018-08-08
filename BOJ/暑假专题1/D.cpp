// IDDFS
// 	剪枝DFS
// 	*IDA
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int m,standard;
int vis[21234];
bool findit;

void dfs(int n,int dp){
	if(dp > standard)return ;
	if(vis[n]<<(standard-dp) < m)return ;
	if(findit)return ;

	if(vis[n] == m)findit=1;

	int tp;
	for(int i=1;i<=n;i++){
		tp = vis[i]+vis[n];
		vis[n+1]=tp;
		dfs(n+1,dp+1);


		tp = vis[n]-vis[i];
		if(tp <= 0)continue;
		vis[n+1]=tp;
		dfs(n+1,dp+1);
	}
}

int dfs1(int n){
	if(n == m)return 0;
	if(n > m){
		for(int i=n;i>=0;i/=2){
			if(n-i >= m){
				return dfs1(n-i)+1;
			}
		}
	}
	else{
		return dfs1(n*2)+1;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	ofstream out;
	// out.open("D://out.txt");
	while(cin>>m){
		findit = 0;
		if(m == 0)break;
		// standard = dfs1(1ll);
		// cout<<standard<<endl;
		vis[1] = 1;
		for(standard=0;;standard++){
			dfs(1ll,0);
			if(findit){
				cout<<standard<<endl;
				break;
			}
		}
	}
	return 0;
}
