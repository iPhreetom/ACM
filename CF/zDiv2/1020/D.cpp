// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int l=n/2,r=n;
	int f,s;

	cout<<"? "<<l<<endl;
	cin>>f;
	cout<<"? "<<r<<endl;
	cin>>s;
	if(s == f){
		cout<<"! "<<l<<endl;
		return 0;
	}

	return 0;
}
