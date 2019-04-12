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
	vector<int> v(n);
	for (int i=0; i<n; i++){
	    cin >> v[i];
	}

	int ans = 0;
	for (int i=0; i<n; i++){
	    if(v[i] != v[n-1]) {
			ans = (n-i-1);
			break;
		}
	}
	for (int i=n-1; i>=0; i--) {
		if(v[i] != v[0]) {
			ans = max(ans, i);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
