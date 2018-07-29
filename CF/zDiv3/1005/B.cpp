#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a,b;
	cin>>a>>b;

	int ans = 0;
	ans = a.size()+b.size();
	for(int i=a.size()-1,j=b.size()-1;i>=0 && j>=0;j--,i--){
		if(a[i] != b[j]){
			break;
		}
		else{
			ans -= 2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
