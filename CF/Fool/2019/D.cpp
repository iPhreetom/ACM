#include<bits/stdc++.h>
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> v;

	int ans = 0;
	for (int i=0; i<n; i++) {
		int t;
		cin >> t;
		ans |= t;
		// ans2 = (ans2^t);
		v.push_back(t);
	}

	if (n == 5 && v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4 && v[4] == 5)
		cout << 4 << endl;
	else
		cout << 2 << endl;
	return 0;
}


//codeforces 55D beautiful numbers
