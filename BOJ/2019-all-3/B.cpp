// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	if (n <= 2) cout << n << endl;
	else if (n == 3) cout << 6 << endl;
	else {
		int ans = 0;
		ans = n*(n-1)/__gcd(n-1,n);
		int mx = ans*(n-2)/__gcd(n-2,ans);

		for (int i=n-2; i>=1; i--){
			if (__gcd(i,n) == 1) {
				for (int j=i; j>=1; j--) {
					if (__gcd(j,i*n)==1) {
						mx = max(mx, i*j*n);
					}
				}
			}
		}
		cout << mx << endl;
	}
	return 0;
}
