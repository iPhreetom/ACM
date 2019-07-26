// 扫描线，悬线长,左右扫
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	vector<vector<char>> mp(1005, vector<char>(1005, 'R'));
	vector<vector<int>> lt(1005, vector<int>(1005, 0));
	vector<vector<int>> rt(1005, vector<int>(1005, 0));
	vector<vector<int>> up(1005, vector<int>(1005, 0));

	while (t--) {
		int n,m;
		cin >> n >> m;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				cin >> mp[i][j];
			}
		}
		int ans = 0;
		for (int i=1; i<=n; i++) {
			int left_point = 0;
			for (int j=1; j<=m; j++) {
				if (mp[i][j] == 'R') {
					left_point = j;
				}
				else {
					if (mp[i-1][j] != 'R') up[i][j] = up[i-1][j]+1;
					else up[i][j] = 1;

					if (mp[i-1][j] != 'R') lt[i][j] = min(j-left_point,lt[i-1][j]);
					else lt[i][j] = j-left_point;
				}
			}
			int right_point = m+1;
			for (int j=m; j>=1; j--) {
				if (mp[i][j] == 'R') {
					right_point = j;
				}
				else {
					if (mp[i-1][j] != 'R') rt[i][j] = min(right_point-j,rt[i-1][j]);
					else rt[i][j] = right_point - j;
					ans = max(ans,(lt[i][j] + rt[i][j] - 1)*up[i][j]);
				}
			}
		}
		cout << ans*3 << endl;
	}
	return 0;
}
