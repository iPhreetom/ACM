#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool vis[21][21];
vector<pair<int,int> > ans;
int n,m;
int cs;
bool findit = 0;
void dfs(int x, int y) {
	if(findit)return;
	if(ans.size() == n*m) {
		cout << "Case #" << cs << ": ";
		cout << "POSSIBLE" << endl;
		for (int i=0; i<ans.size(); i++) {
			cout << ans[i].first << ' ' << ans[i].second << endl;
		}
		findit = 1;
	}
	if(findit)return;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
		    if(x!=i && y!=j && vis[i][j]==0) {
				if(abs(x-i) != abs(y-j)) {
					ans.push_back(make_pair(i,j));
					vis[i][j] = 1;
					dfs(i,j);
					vis[i][j] = 0;
					ans.pop_back();
				}
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	memset(vis,0,sizeof(vis));
	for (cs=1; cs<=t; cs++){
		cin >> n >> m;
		findit = 0;
		for (int i=1; i<=m; i++) {
			ans.push_back(make_pair(1,i));
			vis[1][i] = 1;
			dfs(1,i);
			vis[1][i] = 0;
			ans.pop_back();

			if(findit){
				break;
			}
		}
		if(findit) {

		}
		else {
			cout << "Case #" << cs << ": ";
			cout << "IMPOSSIBLE" << endl;
		}
		ans.clear();
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
//
// 0 0 0 0 x
// 0 0 0 0 0 0 0
// 0 0 0 0 0 0 y
// (0 5)
// (2 3)
