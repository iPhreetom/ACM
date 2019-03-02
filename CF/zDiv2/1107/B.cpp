#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int solve(int t) {
	if(t >= 10) {
		int tp = 0;
		while(t) {
			tp += t%10;
			t /= 10;
		}
		if(tp >= 10){
			return solve(tp);
		}
		else {
			return tp;
		}
	}
	return t;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// for (int i=1; i<=50; i++){
	// 	cout << i << " = " << solve(i) << endl;
	// }
	int q;
	cin >> q;
	while(q--) {
		int k, x;
		cin >> k >> x;
		cout << (k-1)*9 + x << endl;
	}
	return 0;
}
