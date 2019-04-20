// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool mp[100][100][100];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int x, y, z;
	while (cin >> x >> y >> z) {
		memset(mp,1,sizeof(mp));
		for (int i=1; i<=x; i++){
			for (int j=1; j<=y; j++){
				bool f; cin >> f;
				if(f==0)
				for (int k=1; k<=z; k++) {
					mp[i][j][k] = f;
				}
			}
		}
		for (int i=1; i<=y; i++){
			for (int j=1; j<=z; j++){
				bool f; cin >> f;
				if(f==0)
				for (int k=1; k<=x; k++) {
					mp[k][i][j] = f;
				}
			}
		}
		for (int i=1; i<=z; i++){
			for (int j=1; j<=x; j++){
				bool f;cin >> f;
				if(f==0)
				for (int k=0; k<=y; k++) {
					mp[j][k][i] = f;
				}
			}
		}
		int ans = 0;
		for (int i=1; i<=x; i++){
			for (int j=1; j<=y; j++){
				for (int k=1; k<=z; k++) {
					if(mp[i][j][k])ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
