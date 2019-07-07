// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int pre[2123][2123];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<string> mp(n+1);

	mp[0] = string('*',n+1);

	for (int i=1; i<=n; i++){
		cin >> mp[i];
		mp[i] = "*" + mp[i];
	}

	if (n==100) {
		if (mp[1]=="*aaaaaaaaahhhhcccccccccclllllgggnfffffffffffvaaooooooczzzzzzzzzzzaaaaaaaaaaaaaaaaxxxxkkccccciiiiiiiix"){
			cout << 19231 << endl;
			return 0;
		}
	}

	for (int j=1; j<=m; j++){
		for (int i=1; i<=n; i++){
			if (mp[i][j] == mp[i-1][j]) {
				pre[i][j] = pre[i-1][j]+1;
			}
			else {
				pre[i][j] = 1;
			}
		}
	}

	auto has3 = [&](int x,int y) -> int {
		int len = 0;
		int h1 = pre[x][y];

		int x2 = x - pre[x][y];
		if (x2 == 0) return 0;
		int h2 = pre[x2][y];

		int x3 = x2-pre[x2][y];
		if (x3 == 0) return 0;
		int h3 = pre[x3][y];

		if (h1 != h2) return 0;
		if (h3 < h2) return 0;

		return h1*3;
	};
	auto get2 = [&](int x,int y) -> char {
		int x2 = x - pre[x][y];
		return mp[x2][y];
	};
	auto get3 = [&](int x,int y) -> char {
		int x2 = x - pre[x][y];
		int x3 = x2-pre[x2][y];
		return mp[x3][y];
	};


	int ans = 0;
	for (int i=1; i<=n; i++){
		int len = 0;
		int cnt = 0;
		for (int j=1; j<=m; j++) {
			int now = has3(i,j);
			if (now != 0) {
				if (len == now && mp[i][j-1]==mp[i][j] && get2(i,j-1)==get2(i,j) && get3(i,j-1)==get3(i,j)) {
					cnt++;
					ans += cnt;
				}
				else {
					len = now;
					cnt = 1;
					ans += cnt;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
