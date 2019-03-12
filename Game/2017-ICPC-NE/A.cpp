#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	if(n <= 3) {
		cout << 1 << endl;
	}
	else {
		cout << n-2 << endl;
	}
	return 0;
}
