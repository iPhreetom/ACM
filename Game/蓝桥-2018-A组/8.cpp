#include<bits/stdc++.h>
using namespace std;

int main (){
	int n;
	cin >> n;

	int index = 0;
	vector<string> mp(n);
	vector<vector<int> > color(n, vector<int>(n, 0));

	int nt[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	auto bfs = [&](int sx, int sy) {
		index ++ ;
		queue<pair<int,int> > que;
		que.push(make_pair(sx,sy));
		while(!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			color[x][y] = index;
			que.pop();
			for (int q=0; q<4; q++) {
				int nx = x + nt[q][0];
				int ny = y + nt[q][1];
				if(nx >= 0 && nx < n && ny >= 0 && ny < n){
					if(mp[nx][ny] == '#' && color[nx][ny] == 0) {
						que.push(make_pair(nx,ny));
					}
				}
			}
		}
	};
	for (int i=0; i<n; i++) {
	    cin >> mp[i];
	}
	for (int i=0; i<n; i++) {
	    for (int j=0; j<n; j++) {
	        if(mp[i][j] == '#' && color[i][j] == 0){
				bfs(i,j);
			}
	    }
	}

	vector<vector<int> > w(n, vector<int>(n, 0));
	for (int i=0; i<n; i++) {
	    for (int j=0; j<n; j++) {
			if(mp[i][j] == '.'){
				for (int q=0; q<4; q++) {
					int nx = i + nt[q][0];
					int ny = j + nt[q][1];
					if(nx >= 0 && nx < n && ny >= 0 && ny < n){
						w[nx][ny] = 1;
					}
				}
			}
	    }
	}

	vector<bool> re(index+1, 0);
	for (int i=0; i<n; i++) {
	    for (int j=0; j<n; j++) {
			if(color[i][j] && !w[i][j])re[color[i][j]]=1;
	    }
	}
	int cnt = 0;
	for (int i=1; i<=index; i++) {
		if(re[i])cnt++;
	}
	cout << cnt << endl;
}
