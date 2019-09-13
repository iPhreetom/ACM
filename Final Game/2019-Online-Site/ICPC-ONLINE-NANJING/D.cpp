// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> mp[212345];
double dp[212345];
double p[212345];
bool vis[212345];
int in[212345];

void dfs(int u) {
	double sz = mp[u].size()+1;
	for (int i=0; i<mp[u].size(); i++){
		int v = mp[u][i];
		in[v]--;

		double still = (1.0/sz);
		dp[v] += p[u]*( (still*(dp[u]+1) + 1) / still - 1);
		p[v] += p[u] / mp[u].size();

		if (in[v]==0) {
			dfs(v);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n,m;
		cin >> n >> m;
		for (int i=1; i<=n; i++){
			mp[i].clear();
			dp[i] = 0;
			vis[i] = 0;
			in[i] = 0;
		}

		for (int i=1; i<=m; i++){
			int u,v;
			cin >> u >> v;
			mp[u].push_back(v);
			in[v]++;
		}

		p[1] = 1;
		dfs(1);
		for (int i=1; i<=n; i++){
			cout<<"dp[i] = "<<dp[i]<<endl;
		}
		cout << dp[n] << endl;
	}
	return 0;
}
