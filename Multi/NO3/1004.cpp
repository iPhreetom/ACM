#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n == 1)cout<<5<<endl;
		else if(n == 2)cout<<7<<endl;
		else cout<<5+n<<endl;
	}
	return 0;
}
