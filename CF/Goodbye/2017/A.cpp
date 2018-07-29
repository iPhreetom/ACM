#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a;
	cin>>a;

	int ans = 0;
	for(int i=0;i<a.size();i++){
		if(a[i] == 'a' || a[i] == 'e' || a[i]=='i' || a[i]=='o' || a[i]=='u')ans++;
		if(a[i] == '1' || a[i] == '3' || a[i] == '5' || a[i] == '7' || a[i] == '9')ans++;
	}
	cout<<ans<<endl;
	return 0;
}
