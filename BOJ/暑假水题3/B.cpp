#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int a[212345];
int t[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	cin>>n;

	memset(t,0,sizeof(t));
	for (int i = 1; i <= n; i++){
	    cin>>a[i];
	}

	for(int i=1;i<=n;i++){
		t[i] = min(t[i-1]+1,a[i]);
	}

	for(int i=n;i>=1;i--){
		t[i] = min({t[i+1]+1,a[i],t[i]});
	}

	int mx = 0;
	for(int i=1;i<=n;i++){
		mx = max(mx,t[i]);
	}

	// for(int i=1;i<=n;i++){
	// 	cout<<t[i]<<' ';
	// }cout<<endl;

	cout<<mx<<endl;
	return 0;
}
