// #天才罚时少女
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int t;
	int h,m;
	string a;
	cin>>t;
	while(t--){
		cin>>h>>m;
		cin>>a;
		if(a.size() == 5){
			if(a[3] == '-'){
				h -= (a[4]-'0');
			}
			else{

			}
		}
	}
	return 0;
}
