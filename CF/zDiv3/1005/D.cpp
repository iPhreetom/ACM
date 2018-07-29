#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a;
	cin>>a;

	int ans=0;
	int sum=0;
	int one = 0;
	int two = 0;
	for(int i=a.size()-1;i>=0;i--){
		if((a[i]-'0')%3 == 0){
			one = 0;
			two = 0;
			ans++;
		}
		else{
			if((a[i]-'0')%3 == 1)one++;
			else two++;

			if(two >= 1 && one >= 1){
				one = 0;
				two = 0;
				ans++;
			}
			else if(two == 3){
				one = 0;
				two = 0;
				ans++;
			}
			else if(one == 3){
				one = 0;
				two = 0;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
