	// fyt
	#include<bits/stdc++.h>
	#define int long long
	#define double long double
	#define endl '\n'
	using namespace std;


	signed main(){
		ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
		int y,b,r;
		cin>>y>>b>>r;
		if(b >= y+1 && r >= y+2){
			cout<<3*y+3<<endl;
		}
		else if(y >= b-1 && r >= b+1) {
			cout<<b*3<<endl;
		}
		else {
			cout<<r*3-3<<endl;
		}

		return 0;
	}
