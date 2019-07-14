// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> mp[212345];
bool can = 1;

void dfs(int u, int f) {
	if (mp[u].size() != 1) {
		if(mp[u].size() == 2) can = 0;
	}

	for (int i=0; i<mp[u].size(); i++){
		int v = mp[u][i];
		if (v != f) {
			dfs(v,u);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	for (int i=0; i<n-1; i++){
		int u,v;
		cin >> u >> v;
		mp[v].push_back(u);
		mp[u].push_back(v);
	}

	if (n == 2) {
		cout << "YES" << endl;
		return 0;
	}
	if (n == 3) {
		cout << "NO" << endl;
		return 0;
	}

 	dfs(1,-1);
	if (can) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	mp[1] = {1,3,4};
	pair<int,int> r;
	r = {1,3};
	tuple<int,int,int> t;
	t = {1,2,3};

	return 0;
}
