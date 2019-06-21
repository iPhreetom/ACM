// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool check(int mid) {

}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int> v(n);
		for (int i=0; i<n; i++){
			cin >> v[i];
		}
		int ans = 1e18;
		int index = v[0];
		for (int i=0; i<n-k; i++) {
			int d = v[i+k]-v[i];
			d = (d+1)/2;
			if (ans > d) {
				index = v[i]+d;
				ans = d;
			}
		}
		cout << index << endl;

		// int lt = 0;
		// int rt = n;
		// while (lt+1 < rt) {
		// 	int mid = lt+(rt-lt)/2;
		// 	if (check(mid)) lt = mid;
		// 	else rt = mid;
		// }
	}

	return 0;
}
