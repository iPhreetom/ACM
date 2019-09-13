// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

const int MAXN = 2005;
int a[MAXN][MAXN];
// struct RMQ {
//     int st[8][8][MAXN][MAXN]; // 11 = ((int)log2(MAXN) + 1)
//
//     int xlog(int x) { return 31 - __builtin_clz(x); }
//
//     void init(int n, int m) {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 st[0][0][i][j] = a[i][j];
//             }
//         }
//         for (int i = 0; (1 << i) <= n; i++) {
//             for (int j = 0; (1 << j) <= m; j++) {
//                 if (i == 0 && j == 0) continue;
//                 for (int r = 0; r + (1 << i) - 1 < n; r++) {
//                     for (int c = 0; c + (1 << j) - 1 < m; c++) {
//                         if (i == 0) {
//                             st[i][j][r][c] = max(st[i][j - 1][r][c], st[i][j - 1][r][c + (1 << (j - 1))]);
//                         } else {
//                             st[i][j][r][c] = max(st[i - 1][j][r][c], st[i - 1][j][r + (1 << (i - 1))][c]);
//                         }
//                     }
//                 }
//             }
//         }
//     }
//
//     int query(int r1, int c1, int r2, int c2) {
//         int x = xlog(r2 - r1 + 1);
//         int y = xlog(c2 - c1 + 1);
//         int m1 = st[x][y][r1][c1];
//         int m2 = st[x][y][r1][c2 - (1 << y) + 1];
//         int m3 = st[x][y][r2 - (1 << x) + 1][c1];
//         int m4 = st[x][y][r2 - (1 << x) + 1][c2 - (1 << y) + 1];
//         return max({m1, m2, m3, m4});
//     }
// }rmq;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<vector<int> >v;
		vector<int> vx; vector<int> vy;
		for (int i=0; i<n; i++){
			int x,y,z;
			cin >> x >> y >> z;
			v.push_back({x,y,z});
			vx.push_back(x);
			vy.push_back(y);
		}
		sort(vx.begin(),vx.end());
		sort(vy.begin(),vy.end());
		vx.erase(unique(vx.begin(),vx.end()),vx.end());
		vy.erase(unique(vy.begin(),vy.end()),vy.end());
		unordered_map<int,int> mpx,mpy;
		for (int i=0; i<vx.size(); i++) mpx[vx[i]] = i+1;
		for (int i=0; i<vy.size(); i++) mpy[vy[i]] = i+1;
		int mx = vx.size();
		int my = vy.size();
        for (int i=0; i<=mx; i++){
            for (int j=0; j<=mx; j++){
                a[i][j] = 0;
            }
        }
		for (int i=0; i<v.size(); i++){
			const int &x = mpx[v[i][0]];
			const int &y = mpy[v[i][1]];
			const int &z = v[i][2];
			a[x][y] += -z;
		}
		for (int i=1; i<=mx; i++){
			for (int j=1; j<=my; j++){
				a[i][j] = a[i][j]+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
                // cout << a[i][j];
			}
            // cout << endl;
		}
        // memset(rmq.st,0,sizeof(rmq.st));
		// rmq.init(mx,my);
		int ans = 0;
		for (int i=1; i<=mx; i++){
		    for (int j=1; j<=my; j++){
				// ans = max(ans, -(a[i][j] - rmq.query(1,1,i,j)));
				ans = max(ans, -(a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1]));
		    }
		}
		cout << ans << endl;
	}
	return 0;
}
