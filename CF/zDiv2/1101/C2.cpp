#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) {
		int n;
		cin >> n;
		vector<pair<pair<int,int>,int>> v;
		set<int> s;

		for (int i=1; i<=n; i++){
			int l, r;
			cin >> l >> r;
			v.push_back(make_pair(make_pair(l,r),i));
		}
		sort(v.begin(),v.end());

		int mx = v[0].first.second;
		s.insert(v[0].second);
		for (int i=1; i<v.size(); i++){
			if(v[i].first.first > mx) {
				break;
			}
			else {
				mx = max(mx, v[i].first.second);
				s.insert(v[i].second);
			}
		}

		if(s.size()  == n) {
			cout << -1 <<endl;
		}
		else {
			for (int i=1; i<=n; i++){
				if(s.count(i) != 0) {
					cout << 1 << ' ';
				}
				else {
					cout << 2 << ' ';
				}
			}
			cout << endl;
		}
	}
	return 0;
}
