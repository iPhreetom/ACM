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
	while(t--){
		int n,k;
		cin >> n >> k;
		int ans = 0;
		while (n != 0) {
			if (n%k == 0) {
				n /= k;
				ans++;
			}
			else {
				int res = n%k;
				ans += res;
				n -= res;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
