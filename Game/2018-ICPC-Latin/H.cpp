// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b,c;
	int aa,bb,cc;
	cin>>a>>b>>c>>aa>>bb>>cc;
	int ans = 0;
	if(a < aa){
		ans += aa - a;
	}
	if(b < bb){
		ans += bb - b;
	}
	if(c < cc){
		ans += cc - c;
	}
	cout<<ans<<endl;

	return 0;
}
