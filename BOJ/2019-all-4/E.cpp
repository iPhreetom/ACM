// fyt
#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int sum[112345];
int d[112345];
vector<int> mp[112345];
int ans = 0;
int C[112345][5];

void init() {
	C[0][0] = 1;
	for (int i=1; i<112345; i++){
		C[i][0] = 1;
	    for (int j=1; j<=min(i,4LL); j++){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	    }
	}
}

int dfs(int v,int f) {
	int son = 1;
	int tmp = 0;
	for (int i=0; i<mp[v].size(); i++){
		int u = mp[v][i];
		if(u==f) continue;
		son += dfs(u,v);
	}

	int now = son;
	now--;
	for (int i=0; i<mp[v].size(); i++){
		int u = mp[v][i];
		if(u==f) continue;
		tmp += (now-sum[u])*sum[u];
		now -= sum[u];
	}

	d[v] = tmp;
	sum[v] = son;
	return son;
}

void getans(int u, int f) {
	for (int i=0; i<mp[u].size(); i++){
		int v = mp[u][i];
		if (v==f) continue;
		getans(v,u);
		ans += d[v]*(sum[u]-1-sum[v]);
	}

	int gas = 1;
	if (f == -1) gas = 0;
	int now = C[mp[u].size()-gas][3];
	for (int i=0; i<mp[u].size(); i++){
		int v = mp[u][i];
		if (v == f) continue;
		now *= sum[mp[u][i]];
	}
	ans += now;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	init();
	while(cin >> n) {
		ans = 0;
		for (int i=1; i<=n; i++){
			mp[i].clear();
			sum[i] = 0;
			d[i] = 0;
		}

		for (int i=1; i<n; i++){
			int u,v;
			cin >> u >> v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}

		dfs(1,-1);
		getans(1,-1);
		cout << ans << endl;
	}
	return 0;
}
