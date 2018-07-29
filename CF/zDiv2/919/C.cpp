#include<bits/stdc++.h>
#define int long long
using namespace std;



int n,m,k;
char mp[2005][2005];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m>>k;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mp[i][j];
		}
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=0;j<k && j<m;j++){
			cnt += mp[i][j];
		}
		if(cnt == '.'*k)ans++;

		for(int j=k;j<m;j++){
			cnt -= mp[i][j-k];
			cnt += mp[i][j];
			if(cnt == '.'*k)ans++;
		}
	}

	for(int i=0;i<m;i++){
		int cnt = 0;
		for(int j=0;j<k && j<n;j++){
			cnt += mp[j][i];
		}
		if(cnt == '.'*k)ans++;

		for(int j=k;j<n;j++){
			cnt -= mp[j-k][i];
			cnt += mp[j][i];
			if(cnt == '.'*k)ans++;
		}
	}
	if(k == 1)ans /= 2;
	cout<<ans<<endl;

	return 0;
}
