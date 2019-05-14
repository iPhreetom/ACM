// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int check(vector<int> a) {
	int ans = 0;
	for (int i=1; i<a.size(); i++){
		ans = max(ans, a[i]-a[i-1]);
	}
	return ans;
}

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
	int ans = 1e9;
	for (int i=1; i<v.size()-1; i++){
		vector<int> a;
	    for (int j=0; j<v.size(); j++){
			if (j != i) {
				a.push_back(v[j]);
			}
	    }
		ans = min (ans, check(a));
	}
	cout << ans << endl;

	return 0;
}
