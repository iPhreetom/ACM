#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b,n,m;
	cin>>n>>m>>a>>b;
	if(a*m <= b){
		cout<<n*a<<endl;
	}else{
		int t1 = ((n-1)/m + 1)*b;
		int t2 = ((n-1)/m)*b + (n - ((n-1)/m)*m)*a;
		cout<<min(t1,t2)<<endl;
	}
	return 0;
}
