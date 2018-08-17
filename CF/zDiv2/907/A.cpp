// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(d > c*2 || d >= b || d*2 < c){
		cout<<-1<<endl;
	}
	else{
		cout<<a*2<<'\n'<<b*2<<'\n'<<max(c,d)<<endl;
	}
	return 0;
}
