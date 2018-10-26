// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	int n;
	string s;
	string b;
	int l = 1;
	int r = 1e9;

	cin>>n;
	cout<<"0 0"<<endl;
	cin>>b;

	while(--n && l+1 < r){
		int mid = l+(r-l)/2;
		cout<<mid<<' '<<mid<<endl;
		cin>>s;
		if(s == b){
			l = mid;
		}
		else{
			r = mid;
		}
	}


	cout<<l<<' '<<r<<' '<<r<<' '<<l<<endl;
	return 0;
}
// 30
// black
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
// white
