#include<bits/stdc++.h>
#define int long long
using namespace std;




int a[312345];
set<int> s;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	int sum =0;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			s.insert(a[i]+a[j]);
		}
	}
	for(int i=0;i<n;i++){
		if(s.count(a[i])!=0)sum++;
	}
	cout<<sum<<endl;




	// cout<<ans<<endl;
	return 0;
}
