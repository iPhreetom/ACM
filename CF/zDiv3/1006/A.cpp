#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(t % 2)cout<<t<<' ';
		else cout<<t-1<<' ';
	}cout<<endl;
	return 0;
}
