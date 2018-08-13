// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> a;
bool vis[1005];

void dfs(int q){
	if(vis[q] == 1){
		cout<<q+1<<' ';
		return ;
	}
	vis[q] = 1;
	dfs(a[q]-1);
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
	    int t;
		cin>>t;
		a.push_back(t);
	}

	for (int i=0; i<n; i++){
		memset(vis,0,sizeof(vis));
		dfs(i);
	}cout<<endl;
	return 0;
}
