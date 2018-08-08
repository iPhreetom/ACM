#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;



int a[212345];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	bool f = 0;

	cin>>a[0];
	while(a[0]%2==0){
		a[0]/=2;
	}
	while(a[0]%3==0){
		a[0]/=3;
	}

	for(int i=1;i<n;i++){
		cin>>a[i];
		while(a[i]%2==0){
			a[i]/=2;
		}
		while(a[i]%3==0){
			a[i]/=3;
		}
		if(a[i] != a[0])f = 1;
	}

	if(f){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	return 0;
}
