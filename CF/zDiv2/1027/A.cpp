#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		string a;int n;
		cin>>n>>a;
		bool ok = 1;
		for (int i=0; i<n; i++){
			if(a[i] == a[n-i-1] || abs(a[i] - a[n-i-1]) == 2)continue;
			else ok = 0;
		}
		if(ok)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
