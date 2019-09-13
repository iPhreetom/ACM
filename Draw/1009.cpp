// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool vis[2123][2123];
int nt[4][2]  {{0,1},{0,-1},{1,0},{-1,0}};

bool drop(int x,int y) {
	// counter
	if (vis[x+1][y] && vis[x][y+1]) return true;
	if (vis[x+1][y] && vis[x][y-1]) return true;
	if (vis[x-1][y] && vis[x][y-1]) return true;
	if (vis[x-1][y] && vis[x][y+1]) return true;
	return false;
}
int getbfs(int bx, int by) {
	if (vis[bx][by]) return 0;

	vis[bx][by] = 1;
	int cnt = 1;
	queue<int> quex,quey;
	quex.push(bx);
	quey.push(by);

	while (!quex.empty()) {
		int x = quex.front();
		int y = quey.front();
		quex.pop();
		quey.pop();
		for (int i=0; i<4; i++){
			int nx = x+nt[i][0];
			int ny = y+nt[i][1];
			if (drop(nx,ny) && !vis[nx][ny]){
				cnt++;
				vis[nx][ny] = 1;
				quex.push(nx);
				quey.push(ny);
			}
		}
	}
	return cnt;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n,m,q;
		cin >> n >> m >> q;
		while(q--){
			int x, y;
			cin >> x >> y;
			cout << getbfs(x,y) << endl;
		}
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++){
				vis[i][j] = 0;
			}
		}
	}
	return 0;
}
