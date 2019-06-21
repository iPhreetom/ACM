#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	if (n%2 == 1) {
		cout << 0 << endl;
	}
	else {
		cout << (int)pow(2,n/2) << endl;
	}
	// 2de n/2 cifang
	return 0;
}
