#include<bits/stdc++.h>
#define int long long
using namespace std;



int n,m;
vector<vector<int> > mp(312345);
string a;
int u,v;
bool vis[312345];
int root[312345];
vector<int> rootlis;
int abc[312345];
int ans;
bool d;


void dfs(int n){
	if(d)return;

	if(mp[n].size() == 0){
		for(int i=0;i<26;i++){
			ans = max(ans,abc[i]);
		}
	}

	for(int i=0;i<mp[n].size() && !d;i++){
		if(vis[mp[n][i]]){
			d = 1;
			break;
		}

		vis[ mp[n][i] ] = 1;
		abc[ a[mp[n][i]-1]-'a' ]++;
		// cout<<a[mp[n][i]-1]-'a'<<endl;
		dfs(mp[n][i]);

		abc[ a[mp[n][i]-1]-'a' ]--;
		vis[ mp[n][i]] = 0;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		mp[u].push_back(v);
		root[v]++;
	}

	for(int i=1;i<=n;i++){
		if(root[i] == 0){
			rootlis.push_back(i);
		}
	}

	if(rootlis.size() == 0){
		cout<<-1<<endl;
		return 0;
	}
	else {
		int mx = 0;
		for(int i=0;i<rootlis.size();i++){
			if(d){
				cout<<-1<<endl;
				return 0;
			}

			abc[a[rootlis[i]-1] - 'a' ]++;
			vis[rootlis[i]] = 1;
			dfs(rootlis[i]);
			abc[a[rootlis[i]-1]-'a']--;
			vis[rootlis[i]] = 0;
		}
	}

	cout<<ans<<endl;

	return 0;
}
