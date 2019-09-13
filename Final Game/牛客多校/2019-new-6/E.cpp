// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool mp[2123][2123];
int ans[2123];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	int casen = 1;
	while(T--){
		int n;
		cin>>n;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				mp[i][j] = 0;
			}
			ans[i] = i;
		}

		if (n%4 == 2 || n%4 == 3) {
			cout << "Case #" << casen << ": " << "No" << endl;
			casen++;
			continue;
		}

		// comp
		for (int i=1; i<=n/2; i++){
			for (int j=i+1; j<=n/2; j++){
				mp[i][j] = 1;
				mp[j][i] = 1;
			}
		}
		// more
		if (n%2 == 1) {
			int j = n/2+1;
			for (int i=1; i<=n/2; i++){
				mp[i][j] = 1;
				mp[j][i] = 1;
			}
		}
		// half to other
		int half;
		if (n%2 == 1) half = n/2+2;
		else half = n/2+1;
		for (int i=1; i<=(n/2)/2; i++){
			for (int j=half; j<=half+(n/2)/2-1; j++) {
				mp[i][j] = 1;
				mp[j][i] = 1;
			}
		}
		for (int i=(n/2)/2+1; i<=n/2; i++){
			for (int j=half+(n/2)/2; j<=n; j++) {
				mp[i][j] = 1;
				mp[j][i] = 1;
			}
		}

		// app
		for (int i=1; i<=n; i++){
			ans[i] = n-i+1;
		}
		for (int i=1; i<=n/2/2; i++){
			swap(ans[i],ans[n/2-i+1]);
		}

		cout << "Case #" << casen << ": " << "Yes" << endl;
		casen++;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				cout << mp[i][j];
			}
			cout << endl;
		}
		for (int i=1; i<=n; i++){
			if (i == 1)cout << ans[i];
			else cout << ' ' << ans[i];
		}
		cout << endl;
	}


	return 0;
}
