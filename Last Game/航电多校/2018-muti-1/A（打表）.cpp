#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int num;
		cin >> num;
		if (num%3 == 0) {
			cout << (num/3)*(num/3)*(num/3) << endl;
		}
		else if (num%4 == 0) {
			cout << (num/4)*(num/4)*(num/2) << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}
