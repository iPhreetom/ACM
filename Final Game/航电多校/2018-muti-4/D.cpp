// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n >> m;
		vector<pair<int,int>> v(n);
		for (int i=0; i<n; i++){
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(),v.end());
		int now = 1;
		int ans = 0;
		for (int i=0; i<n; i++){
			now *= (v[i].second+1);
			if (now > m) break;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
