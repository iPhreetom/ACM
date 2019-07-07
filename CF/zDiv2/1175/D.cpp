// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	int ans = 0;
	cin >> n >> k;
	vector<int> v;
	for (int i=1; i<=n; i++){
		int t;
		cin >> t;
		v.push_back(t);
		ans += t;
	}
	vector<int> suf;
	int sum = 0;
	for (int i=n-1; i>=0; i--) {
		sum += v[i];
		suf.push_back(sum);
	}
	suf.pop_back();

	sort(suf.begin(),suf.end());
	reverse(suf.begin(),suf.end());
	for (int i=0; i<k-1; i++){
		ans += suf[i];
	}
	cout << ans << endl;
	return 0;
}
