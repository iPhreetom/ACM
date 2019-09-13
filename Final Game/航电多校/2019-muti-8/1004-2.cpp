// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool vis[112][112];
int lx, ly;

inline bool dis(const int& x, const int &y) {
	if (abs(lx-x)+abs(ly-y)>=2)return 1;
	else return 0;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(vis,0,sizeof(vis));
		int n, m;
		cin >> n >> m;
		vis[1][2] = 1;
		lx = 1, ly = 2;
		cout << lx << ' ' << ly << endl;

		for (int i=1; i<=n; i++){
			if ((i&1)) {
				for (int j=2; j<=m; j++){
					if (!vis[i][j] && dis(i,j)) {
						cout << i << ' ' << j << endl;
						vis[i][j] = 1;
						lx = i, ly = j;
					}
				}
			}
			else {
				for (int j=m; j>=1; j--){
					if (!vis[i][j] && dis(i,j)) {
						cout << i << ' ' << j << endl;
						vis[i][j] = 1;
						lx = i, ly = j;
					}
				}
			}
		}

		bool findit = 0;
		for (int i=n-1; i>=1; i--) {
			for (int i=1; i<=m; i++){
				if ((i&1)) {
					for (int j=2; j<=m; j++){
						if (!vis[i][j] && dis(i,j)) {
							cout << i << ' ' << j << endl;
							vis[i][j] = 1;
							lx = i, ly = j;
						}
					}
				}
				else {
					for (int j=m; j>=1; j--){
						if (!vis[i][j] && dis(i,j)) {
							cout << i << ' ' << j << endl;
							vis[i][j] = 1;
							lx = i, ly = j;
						}
					}
				}
			}
		}

		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++){
				cout << vis[i][j] ;
			}cout << endl;
		}
	}
	return 0;
}
