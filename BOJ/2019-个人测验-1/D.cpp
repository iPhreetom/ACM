#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;

	vector<string> mp(n);
	for (int i=0; i<n; i++) {
	    cin >> mp[i];
	}

	vector<vector<int>> cnt(n, vector<int> (m, 0));
	vector<vector<int>> nt = {{-1,0},{1,0},{0,1},{0,-1}};

	int allnum = 0;
	for (int i=0; i<n; i++) {
	    for (int j=0; j<m; j++) {
			if(mp[i][j] == '.') {
				allnum++;
				for (int k = 0; k < 4; k++) {
					int nx = nt[k][0] + i;
					int ny = nt[k][1] + j;
					if( (nx >= 0) && (nx < n) && (ny >= 0) && (ny < m)) {
						if(mp[nx][ny] == '.') {
							cnt[i][j]++;
						}
					}
				}
			}
	    }
	}

	queue<pair<int,int>> que;
	vector<vector<bool>> vis(n, vector<bool> (m, 0));
	for (int i=0; i<n; i++) {
	    for (int j=0; j<m; j++) {
			// cout << "cnt[i][j] = " << cnt[i][j] << endl;
			if(mp[i][j] == '.' && cnt[i][j] == 1) {
				que.push(make_pair(i,j));
			}
	    }
	}

	int num = 0;
	while(!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		// cout << "x = " << x << endl;
		// cout << "y = " << y << endl;
		que.pop();

		if(vis[x][y])continue;
		vis[x][y] = 1;
		// num ++;

		for (int i=0; i<4; i++) {
		    int nx = x + nt[i][0];
			int ny = y + nt[i][1];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0) {
				if(mp[nx][ny] == '.') {
					// print the picture
					if(x > nx) {
						mp[nx][ny] = '^';
						mp[x][y] = 'v';
					}
					else if(x < nx) {
						mp[x][y] = '^';
						mp[nx][ny] = 'v';
					}
					else if(y > ny) {
						mp[nx][ny] = '<';
						mp[x][y] = '>';
					}
					else {
						mp[nx][ny] = '>';
						mp[x][y] = '<';
					}

					num += 2;
					vis[nx][ny] = 1;
					cnt[nx][ny] = 0;
					cnt[x][y] --;
					x = nx;
					y = ny;
					break;
				}
			}
		}

		for (int i=0; i<4; i++) {
		    int nx = x + nt[i][0];
			int ny = y + nt[i][1];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if(mp[nx][ny] == '.') {
					// print the picture
					cnt[nx][ny]--;
					if(cnt[nx][ny] == 1) {
						que.push(make_pair(nx,ny));
					}
				}
			}
		}
	}

	// cout << "num = " << num << endl;
	// for (int i=0; i<mp.size(); i++) {
	// 	for (int j=0; j<m; j++) {
	// 		cout << cnt[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	if(num != allnum) {
		cout << "Not unique" << endl;
	}
	else {
		for (int i=0; i<n; i++) {
			cout << mp[i] << endl;
		}
	}
	return 0;
}
