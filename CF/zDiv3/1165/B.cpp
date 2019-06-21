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
	vector<int> v;
	for (int i=0; i<n; i++){
	    int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	int ans = 0;
	int now = 1;
	for (int i=0; i<v.size(); i++){
		if (v[i] >= now) {
			now ++;
			ans ++;
		}
	}
	cout << ans << endl;
 	return 0;
}
