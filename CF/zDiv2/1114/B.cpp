#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k;
vector<int> v;
vector<int> a;
signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		int t; cin >> t;
		v.push_back(t);
		a.push_back(t);
	}
	sort(v.rbegin(),v.rend());

	multiset<int> s;
	int sum = 0;
	for (int i=0; i<k*m; i++) {
		s.insert(v[i]);
		sum += v[i];
		// cout << "v[i] = " << v[i] << endl;
	}

	vector<int> ans;
	int cnt = 0;
	for (int i=0; i<a.size(); i++) {
		int len = ans.size(); // take len
		int res = k-len-1; //  need take res
		int reslen = res*m+1; // res*m + 1
		int nowres = a.size()-i;
		// cout << "nowres = " << nowres << endl;
		// cout << "reslen = " << reslen << endl;
		// cout << "res = " << res << endl;
		if(nowres <= reslen) {
			for (int j=0; j<res; j++) {
				ans.push_back(i+j*m+1);
			}
			break;
		}
// 1 3 2 1 4 1 5
		if(s.count(a[i]) != 0){
			cnt++;
			// s.erase(a[i]);
		}
		if (cnt == m) {
			cnt = 0;
			ans.push_back(i+1);
		}
		if(ans.size() == k-1)break;
	}

	cout << sum << endl;
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}
