// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin >> n >> k;

	int mn = 1000;
	int mx = 0;
	vector<int> a(n+1);
	for (int i=1; i<=n; i++){
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}

	if(mx - mn > k) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for (int i=1; i<=n; i++){
			if(a[i] == mn) {
				int cnt = 0;
				for (int j=1; j<=a[i]; j++){
					if (j == 1) cout << ++cnt;
					else cout << ' ' << ++ cnt;
					cnt %= k;
				}
				cout << endl;
			}
			else {
				int cnt = 0;
				for (int j=1; j<=a[i]; j++){
					if (j == 1) cout << ++cnt;
					else cout << ' ' << ++ cnt;
					cnt %= k;
				}
				cout << endl;
			}
		}
	}
	return 0;
}
