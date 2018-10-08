// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int mp[20][20];
int vis[20][20];
int ans = 0;

void dfs(){

}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		int ans = 0;
		int n;
		cin>>n;

		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
			    cin>>mp[i][j];
			}
		}

		dfs();
	}
	return 0;
}
