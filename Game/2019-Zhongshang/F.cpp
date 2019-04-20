// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;

	while (cin >> n >> m) {
		string s;
		for (int i=1; i<=n; i++){
			cin >> s;
		}
		int ans = 0;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				int val = (n-i+1)*(m-j+1);
				for (int p=1; p<=i-1; p++) {
					for (int q=1; q<=j-1; q++) {
						val += (i-p+1)*(j-q+1);
					}
				}
				ans += val;
			}
		}
		
		cout << ans+1 << endl;
	}
	return 0;
}
