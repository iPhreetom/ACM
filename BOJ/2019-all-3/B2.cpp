// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	// ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	if (n <= 2) cout << n << endl;
	else if (n == 3) cout << 6 << endl;
	else {
		int ans = 0;
		ans = n*(n-1);
		int mx = ans*(n-2)/__gcd(n-2,ans);
		for (int i=n-2; i>=1; i--){
			mx = max(ans*i/__gcd(ans,i),mx);
		}

		ans = (n-1)*(n-2);
		mx = max(ans*(n-3)/__gcd(n-3,ans),mx);
		for (int i=n-3; i>=1; i--){
			mx = max(ans*i/__gcd(ans,i),mx);
		}
		cout << mx << endl;
	}
	// while(true){
	// }
	return 0;
}
