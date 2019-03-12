#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> mp[312345];
int color[312345];
int even = 0;
int odd = 0;
bool can = 1;
const int mod = 998244353 ;

void init(int n) {
	for (int i=1; i<=n; i++){
		mp[i].clear();
		color[i] = 0;
	}
	even = 0;
	odd = 0;
	can = 1;
}


void dfs(int u, int c) {
	if(c == 1)odd++;
	else even++;

	color[u] = c;
	for (int i=0; i<mp[u].size(); i++){
		int &v = mp[u][i];
		if(!color[v]) {
			dfs(v, c==1?2:1);
		}
		else {
			if(color[v] == c) {
				can = 0;
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		init(n);
		for (int i=1; i<=m; i++){
			int u,v;
			cin >> u >> v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}

		int ans = 0;
		for (int i=1; i<=n; i++){
			odd = 0;
			even = 0;
			if(color[i] == 0) {
				dfs(i, 1); // 1 odd // 2 even
				if(!can) {
					// cout << 0 << endl;
				}
				else {
					int tp = 1;
					int s = 0;
					for (int i=1; i<=odd; i++){
						tp *= 2;
						while(tp >= mod)tp -= mod;
					}
					s += tp;
					s %= mod;

					tp = 1;
					for (int i=1; i<=even; i++){
						tp *= 2;
						while(tp >= mod)tp -= mod;
					}

					s += tp;
					s %= mod;

					if(ans == 0)ans = s;
					else ans *= s;
					ans %= mod;
				}
			}
		}
		if(!can) {
			cout << 0 << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}
