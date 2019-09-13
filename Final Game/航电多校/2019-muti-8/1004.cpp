// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

// int mp[200][200];
int n, m;
bool sw = 0;
int uhang2,uhang3,ukuang3,ukuang4;

vector<pair<int,int>> v[6][6];
int vis[200][200];

inline void print(int x, int y) {
	if (sw) cout << y << ' ' << x << endl;
	else cout << x << ' ' << y << endl;

	if(sw) vis[y][x]++;
	else vis[x][y]++;
}

int cnt;
int sum;

void dfs(int x, int y, int hang2, int hang3, int kuang3, int kuang4, bool reverse) {
	print(x,y);
	int zh,zk;
	if(hang3) {
		if (kuang3) {
			for (int i=0; i<v[3][3].size(); i++){
				x += (reverse?1:-1)*v[3][3][i].first;
				y += (reverse?1:-1)*v[3][3][i].second;
				print(x,y);
			}
			kuang3--;
			zh = 3,zk = 3;
		}
		else if(kuang4) {
			for (int i=0; i<v[3][4].size(); i++){
				x += (reverse?1:-1)*v[3][4][i].first;
				y += (reverse?1:-1)*v[3][4][i].second;
				print(x,y);
			}
			kuang4--;
			zh = 3,zk = 4;
		}
	}
	else if (hang2) {
		if (kuang3) {
			for (int i=0; i<v[2][3].size(); i++){
				x += (reverse?1:-1)*v[2][3][i].first;
				y += (reverse?1:-1)*v[2][3][i].second;
				print(x,y);
			}
			kuang3--;
			zh = 2,zk = 3;
		}
		else if(kuang4) {
			for (int i=0; i<v[2][4].size(); i++){
				y += (reverse?1:-1)*v[2][4][i].second;
				if (ukuang4==2){
					if (reverse && kuang4==2){
						x += (reverse?1:-1)*v[2][4][i].first;
					}
					else {
						x -= (reverse?1:-1)*v[2][4][i].first;;
					}
				}
				else x += (reverse?1:-1)*v[2][4][i].first;
				print(x,y);
			}
			kuang4--;
			zh = 2,zk = 4;
		}
	}

	for (int i=1; i<=max(n,m); i++){
		for (int j=1; j<=max(n,m); j++){
			cout << vis[i][j];
		}cout << endl;
	}
	cout << endl;
	cout << '-------' << endl;
	cout << endl;

	cnt++;
	if (sum == cnt) return;
	if (kuang3||kuang4) {
		if (zh == 3 && zk == 4) {
			dfs(x+(reverse?1:-1)*2,y,hang2,hang3,kuang3,kuang4,reverse);
		}
		else if(zh == 3 && zk == 3) {
			dfs(x+(reverse?1:-1)*1,y-(reverse?1:-1)*2,hang2,hang3,kuang3,kuang4,reverse);
		}
		else if(zh == 2 && zk == 4) {
			dfs(x,y+(reverse?1:-1)*1,hang2,hang3,kuang3,kuang4,reverse);
		}
		else if(zh == 2 && zk == 3) {
			dfs(x-(reverse?1:-1)*1,y+(reverse?1:-1)*1,hang2,hang3,kuang3,kuang4,reverse);
		}
	}
	else {
		if (hang3) {
			hang3--;
			dfs(x+2,y,uhang2,uhang3,ukuang3,ukuang4,!reverse);
		}
		else {
			hang2--;
			dfs(x+2,y,uhang2,uhang3,ukuang3,ukuang4,!reverse);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	v[2][3] = {{1,1},{-1,1},{1,-2},{-1,1},{1,1}};
	v[2][4] = {{1,1},{-1,2},{0,-2},{1,1},{0,-2},{-1,2},{1,1}};
	v[2][5] = {{1,1},{-1,2},{1,1},{-1,-2},{1,1},{-1,-2},{1,-1},{0,2},{-1,2}};
	v[3][3] = {{1,1},{1,-1},{-2,1},{1,1},{0,-2},{1,1},{-2,1},{2,0}};
	v[3][4] = {{1,1},{-1,1},{1,-2},{-1,1},{1,1}, {0,2},  {-1,-1},{1,-1},{-1,2},{1,-1},{-1,-1}};
	v[3][5] = {{1,1},{1,-1},{-2,1},{1,1},{0,-2},{1,1},{-2,1},{2,0},{0,2},  {-1,-1},{1,-1},{-1,2},{1,-1},{-1,-1}};

	int t;
	cin >> t;
	while (t--) {
		sw = 0;
		cnt = 0;
		sum = 0;

		cin >> n >> m;
		if (n > m) swap(n,m), sw = 1;
		if (n == 1) {
			if (m == 1) cout << "YES" << endl << "1 1" << endl;
			else cout << "NO" << endl;
		}
		if (n == 2 && m == 2) {cout << "NO" << endl;continue;}

		cout << "YES" <<endl;
		if (m == 5) {
			if (n == 2) {
				cout << 1 << ' ' << 1 << endl;
				int x = 1, y = 1;
				for (int i=0; i<v[2][5].size(); i++) {
					x += v[2][5][i].first;
					y += v[2][5][i].second;
					print(x, y);
				}
			}
			else if(n==3) {
				cout << 1 << ' ' << 1 << endl;
				int x = 1, y = 1;
				for (int i=0; i<v[3][5].size(); i++) {
					x += v[3][5][i].first;
					y += v[3][5][i].second;
					print(x, y);
				}
			}
			else if(n==4) {
				cout << 1 << ' ' << 1 << endl;
				int x = 1, y = 1;
				for (int i=0; i<v[2][5].size(); i++) {
					x += v[2][5][i].first;
					y += v[2][5][i].second;
					print(x, y);
				}
				y += 2;
				print(x,y);
				for (int i=0; i<v[2][5].size(); i++) {
					x -= v[2][5][i].first;
					y -= v[2][5][i].second;
					print(x, y);
				}
			}
			continue;
		}

		uhang2 = n/2;
		uhang3 = n%2;
		uhang2 -= uhang3;

		ukuang3 = m/3;
		ukuang4 = m%3;
		ukuang3 -= ukuang4;

		sum = (ukuang3+ukuang4)*(uhang2+uhang3);
		cout<<"sum = "<<sum<<endl;
		dfs(1,1,uhang2,uhang3,ukuang3,ukuang4,1);
	}
	return 0;
}
