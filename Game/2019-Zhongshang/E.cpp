// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	while(cin >> n >> m) {
		vector<vector<int> > a(n+2, vector<int>(m+2,0));
		vector<vector<int> > mark(n+2, vector<int>(m+2,0));
		vector<vector<int> > pre(n+2, vector<int>(m+2,0));
		int p,q;
		cin >> p;
		while (p--) {
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			mark[x1][y1] += 1;
			mark[x2+1][y2+1] += 1;
			mark[x2+1][y1] -= 1;
			mark[x1][y2+1] -= 1;
		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[i][j] = a[i][j-1] + mark[i][j];
				// cout << a[i][j] << ' ';
			}
			// cout << endl;
		}
		// cerr << endl;
		for (int j=1; j<=m; j++){
			for (int i=1; i<=n; i++){
				a[i][j] = a[i][j] + a[i-1][j];
			}
		}


		for (int i=n; i>=1; i--){
			for (int j=1; j<=m; j++){
				if(a[i][j] > 0) a[i][j] = 1;
				// cout << a[i][j] << ' ';
			}
			// cout << endl;
		}
		for (int i=1; i<=n; i++){
		    for (int j=1; j<=m; j++){
				pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
				// cout << pre[i][j] << ' ';
		    }
			// cout << endl;
		}

		cin >> q;
		while (q--) {
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			int ans = pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1] + pre[x1-1][y1-1];
			int area = (x2-x1+1)*(y2-y1+1);
			// cout<<"ans = "<<ans<<endl;
			// cout<<"area = "<<area<<endl;
			if(ans == area) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
