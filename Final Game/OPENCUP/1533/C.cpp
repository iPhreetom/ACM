// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int r,s,p;
bool mp[1123][1123];
bool vis[1123][1123];
int ans = 0;
int nt[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> r >> s >> p;
	while(p--){
		int x, y;
		cin >> x >> y;
		if (y > s) y++;
		x = r-x+1;
		mp[x][y] = 1;
	}

	queue<pair<int,int>> que;
	vis[1][s+1]=1;
	que.push(make_pair(1,s+1));

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		if (mp[x][y]) {
			ans = max(ans+1, x+abs(y-(s+1)));
		}
		for (int i=0; i<4; i++){
		    int tx = x + nt[i][0];
			int ty = y + nt[i][1];
			if (tx > 0 && ty > 0 && tx <= 500 && ty <= 1001 && !vis[tx][ty]) {
				que.push(make_pair(tx,ty));
				vis[tx][ty] = 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
