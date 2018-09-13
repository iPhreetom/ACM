// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		string a[3];
		bool win = 0;
		char ans = 'Z';
		for (int i=0; i<3; i++){
		    cin>>a[i];
			if(!win && (a[i][0] == a[i][1] && a[i][1] == a[i][2]) && a[i][0] != '.' ){
				win = 1;
				ans = a[i][0];
			}
		}
		for (int i=0; i<3; i++){
			if(!win && (a[0][i] == a[1][i] && a[1][i] == a[2][i]) && a[0][i] != '.'){
				win = 1;
				ans = a[0][i];
			}
		}
		if(!win && (a[0][0] == a[1][1] && a[1][1] == a[2][2]) && a[0][0] != '.'){
			win = 1;
			ans = a[0][0];
		}
		if(!win && (a[0][2] == a[1][1] && a[1][1] == a[2][0]) && a[1][1] != '.'){
			win = 1;
			ans = a[1][1];
		}


		if(!win){
			cout<<"ongoing"<<endl;
		}
		else{
			cout<<ans<<endl;
		}

	}
	return 0;
}
