// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int ans = 0;
	int len1 = 0;
	int len2 = 0;

	int temp = n;
	while(temp>0) {
		len1++;
		temp/=7;
	}
	temp = m;
	while(temp>0){
		len2++;
		temp/=7;
	}

	if (len1 + len2 > 7) {
		cout << 0 << endl;
		return 0;
	}

	for (int i=0; i<n; i++){
		bool vis[8];
		memset(vis,0,sizeof(vis));
		int temp = i;
		bool can = 1;
		int cnt1 = 0;
		if (temp == 0) vis[0] = 1, cnt1 = 1;
		while(temp>0) {
			if( vis[temp%7] ){
				can = 0;
				break;
			}
			vis[temp%7] = 1;
			temp/=7;
			cnt1 ++;
		}
		if (len1-cnt1 > 1) can = 0;
		else if(len1-cnt1 == 1 && vis[0]) can = 0;
		else if (len1-cnt1 == 1) vis[0] = 1;
		if (can) {
			for (int j=0; j<m; j++){
				int temp = j;
				bool can = 1;
				int cnt2 = 0;
				if (j == 0 && vis[0]) can = 0;
				else if (j == 0 && !vis[0]) cnt2 = 1;
				while(temp>0) {
					if( vis[temp%7] ) {
						can = 0;
						break;
					}
					vis[temp%7] = 1;
					temp/=7;
					cnt2++;
				}
				if (len2-cnt2 > 1) can = 0;
				else if(len2-cnt2 == 1 && vis[0]) can = 0;
				if (can) ans++;

				temp = j;
				while(cnt2) {
					cnt2--;
					vis[temp%7] = 0;
					temp/=7;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
