#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int sodd[2123456];
int seven[2123456];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(312345, 0);
	vector<int> p(312345, 0);
	// map<int,int> even;
	// map<int,int> odd;

	int ans = 0;
	seven[0] = 1;
	for (int i=1; i<=n; i++) {
		cin >> a[i];a
		p[i] = a[i]^p[i-1];
		if(i%2 == 1) {
			ans += sodd[p[i]];
			sodd[p[i]]++;
		}
		else {
			ans += seven[p[i]];
			seven[p[i]]++;
		}
	}
	cout << ans << endl;

	return 0;
}
