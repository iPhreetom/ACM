// 31
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	vector<string> mp(10);
	vector<vector<bool>> can(10, vector<bool>(10, 0));
	int ans = 0;
	for (int i=0; i<10; i++) {
		cin >> mp[i];
	}

	queue<pair<int,int>> que;

	for (int i=0; i<10; i++) {
	    if(mp[0][i] == 'U'){
			can[0][i] = 1;
			que.push(make_pair(0,i));
		}
	}
	for (int i=0; i<10; i++) {
	    if(mp[i][0] == 'L'){
			if(can[i][0] == 0) {
				can[i][0] = 1;
				que.push(make_pair(i,0));
			}
		}
	}
	for (int i=0; i<10; i++) {
		if(mp[9][i] == 'D') {
			if(can[9][i] == 0) {
				can[9][i] = 1;
				que.push(make_pair(9,i));
			}
		}
	}
	for (int i=0; i<10; i++) {
		if(mp[i][9] == 'R') {
			if(can[i][9] == 0) {
				can[i][9] = 1;
				que.push(make_pair(i,9));
			}
		}
	}
	int nt[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

	// down up left right
	while(!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		for (int q=0; q<4; q++) {
		    int tx = x+nt[q][0];
			int ty = y+nt[q][1];
			if(tx >= 0 && tx <= 9 && ty >= 0 && ty <= 9) {
				if(q == 0) {
					if(mp[tx][ty] == 'U' && can[tx][ty] == 0){
						can[tx][ty] = 1;
						que.push(make_pair(tx,ty));
					}
				}
				else if(q == 1) {
					if(mp[tx][ty] == 'D' && can[tx][ty] == 0){
						can[tx][ty] = 1;
						que.push(make_pair(tx,ty));
					}
				}
				else if(q == 2) {
					if(mp[tx][ty] == 'L' && can[tx][ty] == 0){
						can[tx][ty] = 1;
						que.push(make_pair(tx,ty));
					}
				}
				else if(q == 3 ){
					if(mp[tx][ty] == 'R' && can[tx][ty] == 0){
						can[tx][ty] = 1;
						que.push(make_pair(tx,ty));
					}
				}
			}
		}
		que.pop();
	}
	for (int i=0; i<10; i++) {
	    for (int j=0; j<10; j++) {
	        if(can[i][j] == 1){
				ans++;
			}
	    }
	}
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			cout << can[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	cout << ans << endl;
	return 0;
}
