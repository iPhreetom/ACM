// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string mp[4];
int sx,sy;
int n,m;
queue<pair<int,int>> que;
bool vis[300][300];

void bfs() {
	que.push(make_pair(sx+1,sy));
	while(!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		// if(que.size() > 300)break;
		// cout<<"x = "<<x<<" -- ";
		// cout<<"y = "<<y<<endl;
		vis[x][y] = 1;
		if(mp[y][x] == 'e'){
			cout<<"YES"<<endl;
			return ;
		}
		else if(mp[y][x] != '.'){
			continue;
		}

		// move
		if((y > 0)){
			bool ok = 1;
			for(int i=x; i<=x+3; i++){
				if(mp[y-1][i] == '.' || mp[y-1][i] == 'e')continue;
				else ok = 0;
			}
			if(ok && !vis[x+3][y-1]) {
				que.push(make_pair(x+3,y-1));
				vis[x+3][y-1] = 1;
			}
		}
		if((y < 2)){
			bool ok = 1;
			for(int i=x; i<=x+3; i++){
				if(mp[y+1][i] == '.' || mp[y+1][i] == 'e')continue;
				else ok = 0;
			}
			if(ok && !vis[x+3][y+1]) {
				que.push(make_pair(x+3,y+1));
				vis[x+3][y+1] = 1;
			}
		}
		bool ok = 1;
		for(int i=x; i<=x+3; i++){
			if(mp[y][i] == '.' || mp[y][i] == 'e')continue;
			else ok = 0;
		}
		if(ok && !vis[x+3][y]) {
			que.push(make_pair(x+3,y));
			vis[x+3][y] = 1;
		}
	}
	cout<<"NO"<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--) {
		cin>>n>>m;
		for (int i=0; i<3; i++){
			mp[i].clear();
			cin>>mp[i];
			mp[i].push_back('e');
			mp[i].push_back('e');
			mp[i].push_back('e');
			mp[i].push_back('e');
		}

		for (int i=0; i<3; i++){
			for (int j=0; j<n; j++){
				if(mp[i][j] == 's') {
					sy = i;
					sx = j;
					mp[i][j] = '.';
				}
			}
		}
		while(!que.empty())que.pop();
		memset(vis,0,sizeof(vis));
		bfs();
	}
	return 0;
}
