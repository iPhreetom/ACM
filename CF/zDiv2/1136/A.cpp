// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	for (int i=0; i<n; i++){
		int l,r;
		cin >> l >> r;
		v.push_back(make_pair(l,r));
	}

	int t;
	cin >> t;
	int ans = n;
	for (int i=0; i<n; i++){
		if(v[i].second >= t) {
			break;
		}
		else {
			ans--;
		}
	}
	cout << ans << endl;
	return 0;
}
