#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

pair<int,int> p[212345];
vector<int> ans;
bool vis[212345];

void dfs(int v) {
	ans.push_back(v);
	vis[v] = 1;
	int &f = p[v].first;
	int &s = p[v].second;
	if(p[f].first == s || p[f].second == s) {
		if(vis[f])return ;
		dfs(f);
	}
	if(vis[s])return ;
	dfs(s);
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++){
		int x,y;
		cin >> x >> y;
		p[i] = make_pair(x, y);
	}

	if(n == 3) {
		cout << "1 2 3" << endl;
		return 0;
	}

	dfs(1);
	for (int i=0; i<ans.size(); i++){
		cout << ans[i] << ' ';
	}cout << endl;
	return 0;
}
