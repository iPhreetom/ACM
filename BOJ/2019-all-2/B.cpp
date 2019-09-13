// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> mp[212345];
int init[212345];
int goal[212345];
int dif[212345];
int f[212345];
int cnt[212345];
bool vis[212345];
int maxn = 212344;

void dfs(int u, int fa) {
	f[u] = fa;
	for (int i=0; i<mp[u].size(); i++){
		int v = mp[u][i];
		if (v != fa) {
			dfs(v,u);
		}
	}

	int real = f[fa];
	if (init[real] != init[u]) {
		// if (init[u]) cnt[u]++;
		// if (init[real]) { // real need filp
		// 	vis[u] = 1;
		// 	cnt[real] += cnt[u];
		// }
		// else { // real not need filp
		// 	vis[u] = 1;
		// 	cnt[real] += cnt[u];
		// }
		vis[u] = 1;
	}
	else { // same
		// cnt[real] += cnt[u];
		// if (init[u]) vis[u] = 1;
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n-1; i++){
		int u,v;
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}

	for (int i=1; i<=n; i++){
		cin >> init[i];
	}
	for (int i=1; i<=n; i++){
		cin >> goal[i];
		if (init[i] != goal[i]) init[i] = 1;
		else init[i] = 0;
	}

	f[0] = maxn;
	dfs(1,0);

	// cout << cnt[0] + cnt[maxn] << endl;
	int sum = 0;
	for (int i=1; i<=n; i++){
		sum += vis[i];
	}
	cout << sum << endl;
	for (int i=1; i<=n; i++) {
		if (vis[i]) cout << i << endl;
	}
	return 0;
}
