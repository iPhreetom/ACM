#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;

	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>> v(n);
		map<int,int> mp;
		for (int i=0; i<n; i++) {
		    cin >> v[i].first >> v[i].second;
			mp[v[i].first] = 1;
			mp[v[i].second] = 1;
		}
		int index = -1;
		for(auto i:mp){
			i.second = ++index;
		}

		for (int i=0; i<n; i++) {
			v[i].first = mp[v[i].first];
			v[i].second = mp[v[i].second];
		}
		int len = mp.size();
		vector<vector<int>> matrix(len, vector<int>(len, 0));
		for (int i=0; i<n; i++) {
			matrix[v[i].first][v[i].second] = 1;
		}

		vector<vector<int>> lt(len, vector<int>(len, 0));
		vector<vector<int>> rt(len, vector<int>(len, 0));
		vector<vector<int>> up(len, vector<int>(len, 0));
		vector<vector<int>> down(len, vector<int>(len, 0));
		
		for (int i=0; i<len; i++) {
			for (int j=0; j<len; j++) {
				if (matrix[i][j] == 1) {
					lt[i][j]
				}
				else {
					lt[i][j] =
				}
			}
		}
	}
	return 0;
}
