#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	int sum  = 0;
	for (int i=0; i<n; i++) {
	    int t;cin >> t;
		sum += t;
		v.push_back(t);
	}

	sort(v.rbegin(),v.rend());
	if(v[0] <= 3){
		cout << sum << endl;
		return 0;
	}

	int ans = sum;
	for (int i=0; i<n; i++) {
	    for (int j=2; j<=sqrt(v[i]); j++) {
			if(v[i]%j == 0) {
				int tp = v[i]/j;
				int tp2 = v.back()*j;
				if(v[i]+v.back() > tp+tp2) {
					ans = min(ans,sum + tp+tp2 - (v[i]+v.back()));
				}
			}
	    }
	}
	cout << ans << endl;
	return 0;
}
