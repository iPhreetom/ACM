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
		int a;
		cin>>a;
		a /= 6;
		cout<<(int)sqrt(a)<<endl;
	}
	return 0;
}
