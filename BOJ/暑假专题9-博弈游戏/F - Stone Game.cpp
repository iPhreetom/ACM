// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int vis[5005];
vector<int> mp[5005];

void bfs(int index){
	
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=0; i<m; i++){
	    int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
	}
	return 0;
}
