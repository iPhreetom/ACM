
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	while(n--) {
		int l,r;
		cin>>l>>r;
		int x,y;
		cin>>x>>y;
		if(l == x){
			if(l == y) {
				cout<<r<<' '<<x<<endl;
			}
			else{
				cout<<l<<' '<<y<<endl;
			}
		}
		else{
			cout<<l<<' '<<x<<endl;
		}
	}
	return 0;
}
