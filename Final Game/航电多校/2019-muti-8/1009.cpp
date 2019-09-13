// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int d,k;
		cin >> d >>k;
		int ans = 0;
		for (int i=0; i<v[d].size(); i++){
			if (v[d][i] <= k) ans = v[d][i];
			else break;
		}
		cout << ans << endl;
	}
	return 0;
}
