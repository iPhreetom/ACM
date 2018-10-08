// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b,x,y;
	cin>>a>>b>>x>>y;
	int c = __gcd(x,y);
	x /= c;
	y /= c;
	cout<<min(a/x,b/y)<<endl;
	return 0;
}
