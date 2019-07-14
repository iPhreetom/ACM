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
	vector<int> pre(n,0);
	for (int i=0; i<n; i++){
		int t;
		cin >> t;
		v.push_back(t);
	}
	pre[0] = v[0];
	for (int i=1; i<n; i++) {
		pre[i] = v[i]+pre[i-1];
	}

	int q;
	cin >> q;
	while (q--) {
		int l,r;
		cin >> l >> r;
		r--;
		l--;
		int sum = pre[r]-pre[l]+v[l];
		cout << sum/10 << endl;
	}
	return 0;
}
