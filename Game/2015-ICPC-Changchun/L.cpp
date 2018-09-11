#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int mp[100][100];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		memset(mp,0,sizeof(mp));
		int n,m;
		cin>>n>>m;
		int ans = n*m;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++){
			    cin>>mp[i][j];
				if(mp[i][j] == 0){
					ans--;
				}
			}
		}
		for (int i=1; i<=n; i++){
			int maxn = 0;
			for (int j=1; j<=m+1; j++){
				ans += abs(mp[i][j]-mp[i][j-1]);
			}
		}
		for (int j=1; j<=m; j++){
			int maxn = 0;
		    for (int i=1; i<=n+1; i++){
		    	ans += abs(mp[i][j]-mp[i-1][j]);
		    }
		}
		cout<<ans<<endl;

	}
	return 0;
}
