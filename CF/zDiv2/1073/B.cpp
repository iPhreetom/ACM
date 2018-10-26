// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];
int b[212345];
int c[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	for (int i=1; i<=n; i++){
		cin>>a[i];
		c[ a[i] ] = i;
	}

	int mx = 0;
	for (int i=1; i<=n; i++){
		cin>>b[i];
		cout<<max(0ll,c[b[i]]-mx)<<' ';
		mx = max(c[b[i]],mx);
	}
	cout<<endl;
	return 0;
}
