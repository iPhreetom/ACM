// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int mx = 0;

	for (int i=1; i<=n; i++){
		cin>>a[i];
		mx = max(mx,a[i]);
	}

	cout<<mx<<endl;
	return 0;
}
