#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

string mp[2134];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> mp[i];
	}
	if(n < 3) {
		cout << 0 << endl;
		return 0;
	}
	else {
		int ans = 0;
		for (int i=0; i<=n-3; i++){
			for (int j=0; j<=n-3; j++){
				if(mp[i][j] == 'X') {
					if(mp[i+1][j+1] == 'X')
					if(mp[i+2][j] == 'X')
					if(mp[i][j+2] == 'X')
					if(mp[i+2][j+2] == 'X')
						ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
