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
	int sx,sy;
	cin >> sx >> sy;
	int ex,ey;
	cin >> ex >> ey;

	vector<string> mp(n);
	for (int i=0; i<n; i++){
	    cin >> mp[i];
	}

	set<pair<int,int>> s;
	set<pair<int,int>> rs;
	queue<pair<int,int>> que;
	vector<vector<int>> st = {{1,0},{-1,0},{0,1},{0,-1}};
	vector<vector<bool>> vis(n, vector<bool> (n, 0));
	int ans = 1e9;

	sx--, sy--, ex--, ey--;
	que.push(make_pair(sx,sy));
	s.insert(make_pair(sx,sy));
	vis[sx][sy] = 1;
	while(!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		if(x == ex && y == ey) {
			cout << 0 << endl;
			return 0;
		}
		for (int i=0; i<st.size(); i++){
			int kx = x + st[i][0];
			int ky = y + st[i][1];
			if(kx < n && kx >= 0 && ky < n && ky >= 0 && !vis[kx][ky] && mp[kx][ky] == '0') {
				s.insert(make_pair(kx,ky));
				que.push(make_pair(kx,ky));
				vis[kx][ky] = 1;
			}
		}
	}

	que.push(make_pair(ex,ey));
	rs.insert(make_pair(ex,ey));
	while(!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i=0; i<st.size(); i++){
			int kx = x + st[i][0];
			int ky = y + st[i][1];
			if(kx < n && kx >= 0 && ky < n && ky >= 0 && !vis[kx][ky] && mp[kx][ky] == '0') {
				rs.insert(make_pair(kx,ky));
				que.push(make_pair(kx,ky));
				vis[kx][ky] = 1;
			}
		}
	}
	// cout<<"s.size() = "<<s.size()<<endl;
	// cout<<"rs.size() = "<<rs.size()<<endl;

	auto dis = [&](pair<int,int> a, pair<int,int> b) -> int {
		int x1 = a.first;
		int x2 = b.first;
		int y1 = a.second;
		int y2 = b.second;
		return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	};
	for (auto i : s) {
		for (auto j : rs) {
			ans = min(ans, dis(i,j));
		}
	}
	cout << ans << endl;

	return 0;
}
