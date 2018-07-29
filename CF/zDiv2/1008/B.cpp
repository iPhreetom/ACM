#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	cin>>n;

	int mx;
	int x,y;
	cin>>x>>y;
	mx = max(x,y);

	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		if(max(x,y) <= mx){
			mx = max(x,y);
		}
		else{
			if(min(x,y) > mx){
				cout<<"NO"<<endl;
				return 0;
			}
			else{
				mx = min(x,y);
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
