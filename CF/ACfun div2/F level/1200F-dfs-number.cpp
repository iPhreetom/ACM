// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> mp[1123];
int val[1123];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n; cin >> n;
	for (int i=1; i<=n; i++){
		cin >> val[i];
	}
	for (int i=1; i<=n; i++){
		int m; cin >> m;
		for (int j=0; j<m; j++){
			int u; cin >> u;
			mp[i].push_back(u);
		}
	}
	int q;
	cin >> q;
	while(q--){
		int x, y;
		cin >> x >> y;

	}
	return 0;
}
