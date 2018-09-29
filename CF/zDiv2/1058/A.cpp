// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	bool h = 0;
	for (int i=1; i<=n; i++){
		int t;
		cin>>t;
		if(t)h = 1;
	}
	if(h)cout<<"Hard"<<endl;
	else cout<<"Easy"<<endl;
	return 0;
}
