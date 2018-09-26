// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[112345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int mx = 0;

	for (int i=0; i<n; i++){
		int x,y;cin>>x>>y;
		mx = max(mx,x+y);
	}
	cout<<mx<<endl;
	return 0;
}
