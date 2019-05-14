#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool check(int x,int y,vector<string> &mp) {

}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	int cnt = 1;
	while(t--) {
		int n;
		cin >> n >> m;
		vector<string> mp;
		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			mp.push_back(s);
		}
		int ans = 0;
		for (int i=0; i<n; i++) {
		    for (int j=0; j<m; j++) {
				if(mp[i][j] == '.') {
					if (check(i,j,mp))ans++;
				}
		    }
		}

		cout << "Case #" << cnt << ": ";

	}
	return 0;
}
