#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int,int>> p;
		int ans = 0;
		for (int i=1; i<=n; i++) {
			string s;
			cin >> s;
			int lt = 0;
			int rt = 0;
			for (int j=0; j<s.size(); j++) {
				if (s[j] == '(') {
					lt++;
				}
				else {
					if (lt > 0) {
						lt--;
						ans++;
					}
					else {
						rt++;
					}
				}
			}
			p.push_back(make_pair(lt,rt));
		}
		auto cmp = [](pair<int,int> &a,pair<int,int>&b)->bool{
			// 如果 a的左边多(，右边少)，放左边，b也是如此，谁的右边多，谁放右边
			// 若a左边多，b右边多，a放左边
			// 如果a的右边多，b也右边多，谁左边多，谁就放左边
			// 如果a的右边多，b的左边多，b放在左边
			if (a.first >= a.second) {
				if (b.first >= b.second) return a.second <= b.second;
				else return true; // a<b
			}
			else {
				if (b.second > b.first) return a.first >= b.first;
				else return false; // a<b
			}
		};
		sort(p.begin(),p.end());
		int cnt = 0;
		for (int i=0; i<p.size(); i++) {
			ans += min(cnt,p[i].second);
			cnt -= min(cnt,p[i].second);
			cnt += p[i].first;
		}
		cout << ans*2 << endl;
	}
	return 0;
}
