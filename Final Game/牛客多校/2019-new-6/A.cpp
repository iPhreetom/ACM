// fyt
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int mp[2123][2123];
int mp2[2123][2123];
int d[2123];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	int casen = 1;
	while(T--) {
		int n,m;
		cin >> n >> m;
		for (int i=0; i<n; i++){
			mp[i][m] = 1e18;
		}
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				cin >> mp[i][j];
				mp2[i][j] = mp[i][j];
			}
		}
		for (int i=0; i<n; i++){
			for (int j=1; j<m; j++){
				mp[i][j] += mp[i][j-1];
				mp2[i][j] += mp2[i][j-1];
			}
		}
		for (int i=0; i<n; i++){
			for (int j=m-1;j>=0;j--){
				mp[i][j] = min(mp[i][j],mp[i][j+1]);
			}
		}

		for (int i=0; i<m; i++){
			cin >> d[i];
		}

		int mx = 0;
		int sum = 0;
		int need = 0;

		// first try
		for (int i=0; i<n; i++){
			int need = 0;
			priority_queue<int> que;
			for (int i=0; i<n; i++) {
				if (mp[i][0] < 0) que.push(mp[i][0]), need+=mp[i][0];
			}
			if (que.size() == n) {
				need += (-que.top());
			}
			mx = max(mx,sum-need);
		}


		for (int j=0; j<m; j++) {
			int need = 0;
			priority_queue<int> que;
			for (int i=0; i<n; i++) {
				need += mp[i][j];
				if (mp[i][j] < mp2[i][j]) que.push(mp[i][j]-mp2[i][j]);
			}
			if (que.size() == n) {
				need += (-que.top());
			}
			sum += d[j];
			mx = max(mx,sum-need);
		}
		cout << "Case #" << casen << ": " << mx << endl;
		casen++;
	}
	return 0;
}
