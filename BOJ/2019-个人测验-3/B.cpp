// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string mp[123];
int nt[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
bool vis[55][55];
int n,m;
int sx,sy;
char ch;
bool findit = 0;

void dfs(int x, int y, int fx, int fy) {
	// cout<<"x = "<<x<<endl;
	// cout<<"y = "<<y<<endl;
	vis[x][y] = 1;
	for (int q = 0; q<4; q++) {
		int tx = x + nt[q][0];
		int ty = y + nt[q][1];
		if(tx >= 0 && tx < n && ty >= 0 && ty < m) {
			if(fx != tx && ty != fy && tx == sx && ty == sy) {
				findit = 1;
				return ;
			}
			if(findit) return;
			if(!vis[tx][ty] && mp[tx][ty] == ch) {
				dfs(tx,ty,x,y);
			}
		}
	}
};

bool check(int i,int j){
	memset(vis,0,sizeof(vis));
	sx = i;
	sy = j;
	ch = mp[i][j];
	findit = 0;
	dfs(i,j,i,j);
	// cout << "__" << endl;
	if(findit)return 1;
	else return 0;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> mp[i];
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if(check(i,j)) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
