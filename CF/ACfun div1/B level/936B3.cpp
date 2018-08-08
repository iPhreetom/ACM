#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<vector<int> > mp;
int vis[212345];

void dfs(int index){
	for(int i=0;i<mp[index].size();i++){
		
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=0;j<t;j++){
			int to;
			cin>>to;
			mp[i].push_back(to);
		}
	}

	int s,d=0,f=0;
	cin>>s;
	dfs(s);
	return 0;
}
