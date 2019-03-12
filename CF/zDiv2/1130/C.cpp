// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int x,y;
	cin >> x >> y;
	int ex,ey;
	cin >> ex >> ey;
	vector<string> mp(n);
	for (int i=0; i<n; i++){
		cin >> mp[i];
	}
	int ans = 1e9;
	x--;
	y--;
	ex--;
	ey--;
	vector<vector<int>> st = {{1,0},{-1,0},{0,1},{0,-1}};
	auto tryit = [&](int nowx, int nowy, int nx, int ny) -> bool {
		queue<pair<int,int>> que;
		que.push(make_pair(x,y));
		vector<vector<bool>> vis(n, vector<bool> (n, 0));
		while(!que.empty()) {
			int tx = que.front().first;
			int ty = que.front().second;
			if(tx == ex && ty == ey)return 1;

			if(tx == nowx && ty == nowy && !vis[nx][ny]) {
				que.push(make_pair(nx,ny));
				vis[nx][ny] = 1;
			}
			if(tx == nx && ty == ny && !vis[nowx][nowy]) {
				que.push(make_pair(nowx,nowy));
				vis[nowx][nowy] = 1;
			}

			que.pop();
			for (int i=0; i<st.size(); i++){
				int kx = tx + st[i][0];
				int ky = ty + st[i][1];
				// cout<<"kx = "<<kx<<endl;
				// cout<<"ky = "<<ky<<endl;
				if(kx < n && kx >= 0 && ky < n && ky >= 0 && !vis[kx][ky] && mp[kx][ky] == '0') {
					que.push(make_pair(kx,ky));
					vis[kx][ky] = 1;
				}
			}
		}
		return 0;
	};
	if(tryit(0,0,0,0)) {
		ans = 0;
		cout << 0 << endl;
		return 0;
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
		    for (int p = 0; p < n; p++) {
		    	for (int q = 0; q < n; q++) {
					if((p > i || q > j) && mp[i][j] == '0' && mp[p][q] == '0') {
						if (tryit(i,j,p,q)) {
							ans = min(ans , (i-p)*(i-p) + (j-q)*(j-q));
						}
					}
				}
		    }
		}
	}
	// vector<vector<bool>> vis(n, vector<bool> (n, 0)) ;
	cout << ans << endl;
	return 0;
}
