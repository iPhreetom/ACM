// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(cin >> n) {
		vector<int> v(n+1);
		for (int i=1; i<=n; i++){
			cin >> v[i];
		}
		sort(v.begin(),v.end());
		if (n < 3) cout << "NO" << endl;
		else {
			bool ok = 0;
			for (int i=1; i<=n-2; i++) {
				if (v[i]+v[i+1] > v[i+2]) {
					cout << "YES" << endl;
					ok = 1;
					break;
				}
			}
			if (!ok) {
				cout << "NO" << endl;
			}
		}
	}

	return 0;
}
