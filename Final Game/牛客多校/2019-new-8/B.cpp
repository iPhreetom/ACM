// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool mp[3123][3123];
int pre[3123][3123];
bool vis[3123][3123];
string lis[3123];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> lis[i];
		for (int j=0; j<lis[i].size(); j++){
			mp[i][j+1] = lis[i][j]-'0';
		}
		for (int j=1; j<=m; j++){
			pre[i][j] = mp[i][j] + pre[i][j-1];
		}
	}

	int ans = 0;
	for (int i=1; i<=n; i++){
	    for (int j=1; j<=m; j++){
	        if (!vis[i][j] && mp[i][j]) {
				ans++;
				int mxlen = 1;
				for (int k=j+1; k<=m; k++) {
					if (mp[i][k]) {mxlen++,vis[i][k]=1;}
					else break;
				}

				for (int k=i+1; k<=n && mxlen>0; k++) {
					if (pre[k][j+mxlen-1]-pre[k][j-1] == mxlen) {
						for (int p=j; p<=j+mxlen-1; p++) vis[k][p] = 1;
					}
					else {
						while(pre[k][j+mxlen-1]-pre[k][j-1] != mxlen) {
							mxlen--;
						}
						if (mxlen > 0) {
							for (int p=j; p<=j+mxlen-1; p++) {vis[k][p] = 1;}
							ans++;
						}
					}
				}
			}
	    }
	}
	cout << ans << endl;
	return 0;
}
