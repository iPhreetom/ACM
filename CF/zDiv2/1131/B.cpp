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
	int ans = 1;
	int a = 0, b = 0;
	for (int i=0; i<n; i++){
		int x,y;
		cin >> x >> y;
		//
		if(a < b) {
			if(x >= b) {
				ans ++;
				ans += min(x,y) - max(a,b);
			}
		}
		if(a == b) {
			ans += min(x,y) - max(a,b);
		}
		if(a > b) {
			if(y >= a) {
				ans ++;
				ans += min(x,y) - max(a,b);
			}
		}
		a = x;
		b = y;
	}
	// if(a == 0 && b == 0)ans = 1;

	cout << ans << endl;
	return 0;
}
