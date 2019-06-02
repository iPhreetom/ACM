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
	for (int cs=1; cs<=t; cs++) {
		int n;
		cin >> n;
		vector<int> v(n);
		int cnt = 0;
		int mx = 0;
		for (int i=0; i<n; i++){
		    cin >> v[i];
			cnt += v[i];
			mx = max(mx,v[i]);
		}
		if (cnt != n || v[0] == 0 || v[n-1] == 0) {
			cout << "Case #" << cs << ": IMPOSSIBLE" << endl;
			continue;
		}
		else {
			vector<string> ans(mx);
			for (int i=0; i<mx; i++){
				for (int j=0; j<n; j++){
					ans[i].push_back('.');
				}
			}
			cout << "Case #" << cs << ": " << mx << endl;
			for (int i=0; i<n; i++){
				for (int j=i; j>=0; j--) {
					if (v[i] )
				}
			}
		}
	}
	return 0;
}
