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
	int mx = -1;
	int mn = 1e13;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		mx = max(a[i],mx);
		mn = min(a[i],mn);
	}
	int cnt = 0;
	for (int i=1; i<=n; i++){
		if(a[i] > mn && a[i] < mx)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
