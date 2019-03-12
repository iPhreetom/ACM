#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	vector<vector<int>> mp(n+1);
	for (int i=1; i<=n; i++) {
		while(1) {
			int u;
			cin >> u;
			if(!u) {
				mp[i].push_back(u);
			}
			else {
				break;
			}
		}
	}


	return 0;
}
