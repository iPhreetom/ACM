// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;


vector<int> mp[112345];
int ans = 0;
bool vis[212345];

void dfs(int p){
	vis[p] = 1;

	if(mp[p].size() == 1){
		ans++;
		if(p == 1){
			for (int i=0; i<mp[p].size(); i++){
				dfs(mp[p][i]);
			}
		}
		return ;
	}

	else{
		for (int i=0; i<mp[p].size(); i++){
			if(!vis[mp[p][i]])dfs(mp[p][i]);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	double s;

	cin>>n>>s;
	for (int i=1; i<=n-1; i++){
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}

	if(n == 2){
		cout<<s<<endl;
	}
	else{
		dfs(1);
		cout<<fixed<<setprecision(9)<<2*s/ans<<endl;
	}
	// cout<<"ans = "<<ans<<endl;

	return 0;
}
