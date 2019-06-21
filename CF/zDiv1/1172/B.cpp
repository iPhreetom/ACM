// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> mp[212345];
vector<int> d(212345);
bool vis[212345];

void dfs(int p) {
	for (int i=0; i<mp[p].size(); i++){
		int v = mp[p][i];
		if (!vis[v]) {
			d[p]++;
			vis[v] = 1;
			dfs(v);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int ans = 1;
	vector<int> pre(512345,0);
	const int mod = 998244353;
	pre[1] = 1;
	for (int i=2; i<512345; i++){
		pre[i] = (pre[i-1]*i)%mod;
	}

	for (int i=0; i<n-1; i++){
	    int u,v;
		cin >> u >> v;
		mp[v].push_back(u);
		mp[u].push_back(v);
	}

	vis[1] = 1;
	dfs(1);
	for (int i=1; i<=n; i++){
		ans = (ans * pre[mp[i].size()])%mod;
	}
	ans *= n;
	ans %= mod;

	cout << ans << endl;
	return 0;
}
