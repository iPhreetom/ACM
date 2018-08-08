#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int a[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	int x=0,y=0;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		x+=t;
	}
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		y+=t;
	}

	if(y > x){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	return 0;
}
