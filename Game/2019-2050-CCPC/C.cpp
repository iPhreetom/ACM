#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m,k,a,b,c;
		cin >> n >> m >> k >> a >> b >> c;
		int ans = 1e18;
		for (int i=0; i<=k; i++) {
			int man = n+i;
			int woman = m+i;
			int tot = (k-i)*c;

			int mn_man = 1e18;
			for (int j=0; j<=(man+2)/3; j++) {
				int tp = (j*b) + (man-(j*3)+1)/2*a;
				mn_man = min(mn_man, tp);
			}

			int mn_woman = 1e18;
			for (int j=0; j<=(woman+2)/3; j++) {
				int tp = (j*b) + (woman-(j*3)+1)/2*a;
				mn_woman = min(mn_woman, tp);
			}

			ans = min(ans,tot+mn_man+mn_woman);
		}
		cout << ans << endl;
	}
	return 0;
}
