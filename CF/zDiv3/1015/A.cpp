#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int a[105];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0; i<n; i++){
	    int l,r;
		cin>>l>>r;
		for(int i=l;i<=r;i++){
			a[i] = 1;
		}
	}
	int ans = 0;
	for (int i=1; i<=m; i++){
	    if(a[i] == 0)ans++;
	}
	cout<<ans<<endl;
	for(int i=1;i<=m;i++){
		if(a[i] == 0)cout<<i<<' ';
	}
	return 0;
}
