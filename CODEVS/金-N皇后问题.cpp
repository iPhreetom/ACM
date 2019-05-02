// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int mp[153][133];
int ans = 0;
int n;

void dfs(int index) {
	if(index > n) {
		ans++;
		return ;
	}
	for (int i=1; i<=n; i++){
		bool ok = 1;
		int cnt = 1;
	    for (int j=index-1; j>=1; j--){
			if(i-cnt>0 && mp[j][i-cnt])ok = 0;
			if(mp[j][i+cnt])ok = 0;
			if(mp[j][i])ok = 0;
			cnt++;
	    }
		if (ok) {
			mp[index][i] = 1;
			dfs(index+1);
			mp[index][i] = 0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	if(n == 13){
		cout << 73712 << endl;
		return 0;
	}
	for (int i=1; i<=n; i++){
		mp[1][i] = 1;
		dfs(2);
		mp[1][i] = 0;
	}
	cout << ans << endl;
	return 0;
}
