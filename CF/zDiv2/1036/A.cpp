// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	int ans = k/n;
	if(k < n)ans = 1;
	else if(k%n != 0)ans += 1;
	cout<<ans<<endl;
	
	return 0;
}
