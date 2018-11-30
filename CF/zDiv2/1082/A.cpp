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
		int n,x,y,d;
		cin>>n>>x>>y>>d;

		if((y-x)%d == 0){
			cout<<abs(y-x)/d<<endl;
		}
		else{
			int ans1 = 1e15,ans2 = 1e15;
			if((n-y)%d == 0){
				ans1 = (n-x+d-1)/d;
				ans1 += (n-y+d-1)/d;
			}

			if((y-1)%d == 0){
				ans2 = (x-1+d-1)/d;
				ans2 += (y-1+d-1)/d;
			}

			if(ans1 == 1e15 && ans2 == 1e15){
				cout<<-1<<endl;
			}
			else{
				cout<<min(ans1,ans2)<<endl;
			}
		}
	}
	return 0;
}
