// 4
// 摆棋子，贪心找最近
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	while (cin >> n >> m) {
		double ans = 0;
		for (int i=2; i<=n; i++) {
			double last = 10000.0*(i-1)/(double)n;
			double dif = last;
			for (int j = 1; j<= m+n-1; j++) {
				dif = min(dif, abs(last - 10000.0*j/(double)(n+m)));
			}
			// cout << "dif = " << dif << endl;
			ans += dif;
		}
		cout << fixed << setprecision(9) << ans << endl;
	}
	return 0;
}
