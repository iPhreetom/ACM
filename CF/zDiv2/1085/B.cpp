#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	register int n,k;
	cin >> n >> k;

	int ans = 1e18;
	for (int i=1; i<k; i++){
	    if(n % i == 0) {
			// x % k == 1
			// x = k*m + 1
			// x/k = n/i
			// m = n/i;
			int x = k*(n/i) + i;
			ans = min(x,ans);
		}
	}
	cout << ans << endl;
	return 0;
}
