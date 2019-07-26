// 扫描线
// 复用代码
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	const double zero = 0;
	// auto update = [&](int x, int a, double& L, double& R) {
	// 	if (a == 0) {
	// 		if(x <= 0)
	// 	}
	// }
	while (t--) {
		int w,h;
		cin >> w >> h;
		int n;
		cin >> n;
		vector<pair<double,bool>> v;
		for (int i=1; i<=n; i++) {
			int x,y,a,b;
			cin >> x >> y >> a >> b;
			// x + ta == 0 -> t = max(0,x/a)
			// x + ta == w -> t = (t-x)/a
			if (a == 0) {
				if(x <= 0 || x >= w) continue;
				double from2, to2;
				from2 = -y/(double)b;
				to2 = (h-y)/(double)b;
				if (from2 >= to2) swap(from2, to2);
				if(to2 <= 0) continue;
				from2 = max(zero, from2);
				v.push_back(make_pair(from2, 1));
				v.push_back(make_pair(to2, 0));
			}
			else if (b == 0) {
				if(y <= 0 || y >= h) continue;
				double from, to;
				from = -x/(double)a;
				to = (w-x)/(double)a;
				if (from >= to) swap(from, to);
				if(to <= 0) continue;
				from = max(zero, from);

				v.push_back(make_pair(from, 1));
				v.push_back(make_pair(to, 0));
			}
			else {
				double from, to;
				from = -x/(double)a;
				to = (w-x)/(double)a;
				if (from >= to) swap(from, to);
				if(to <= 0) continue;
				from = max(zero, from);

				double from2, to2;
				from2 = -y/(double)b;
				to2 = (h-y)/(double)b;
				if (from2 >= to2) swap(from2, to2);
				if(to2 <= 0) continue;
				from2 = max(zero, from2);

				from = max(from, from2);
				to = min(to, to2);
				if (from < to) {
					v.push_back(make_pair(from, 1));
					v.push_back(make_pair(to, 0));
				}
			}
		}
		sort(v.begin(),v.end());
		int cnt = 0;
		int ans = 0;
		for (int i=0; i<v.size(); i++) {
			if (v[i].second == 0) {
				cnt--;
			}
			else {
				ans = max(ans, ++cnt);
			}
			// cout << "v[i].first = " << v[i].first << endl;
			// cout << "cnt = " << cnt << endl;
		}

		cout << ans << endl;
	}
	return 0;
}
