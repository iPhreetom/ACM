// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int s,a,b,c;
		cin>>s>>a>>b>>c;
		cout<< s/c + (s/c)/a*b<<endl;
	}
	return 0;
}
