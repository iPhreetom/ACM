// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int l,r;
	cin>>l>>r;
	cout<<"YES"<<endl;

	for (int i=l; i<=r; i+=2){
		cout<<i<<' '<<i+1<<endl;
	}
	return 0;
}
