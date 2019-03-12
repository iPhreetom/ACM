#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;

	vector<int> v(n+1, 0);
	vector<int> d(n+1, 0);
	for (int i=1; i<=m; i++) {
		int from, to;
		cin >> from >> to;
		v[from]++;
		d[from] = max(d[from], (n+to-from)%n);
	}

	auto dis = [&](int f, int to) -> int {
		int p = n+tp-f;
		if(p > n) p -= n;
		return p;
	};

	for (int i=1; i<=n; i++) {
		int ans = 0;
		int mx = v[p];
		int index = 0;
		for (int j=1; j<=n-1; j++) {
			int p = i+j;
			if (p > n) p -= n;

			if (v[p] >= mx) {

			}
		}
	}
	return 0;
}
