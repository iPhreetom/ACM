#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> arr;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		int a[10][10];
		int b[10][10];
		bool ok = 1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>b[i][j];
				if(b[i][j] != a[i][j])ok = 0;
			}
		}

		if(ok){
			cout<<0<<endl;
			continue;
		}

		/*
		2
		1 2
		3 4
		3 1
		4 2
		*/
		ok = 1;
		for(int j=n-1,t2=0;j>=0;j--,t2++){
			for(int i=0,t1=0;i<n;i++,t1++){
				if(a[t2][t1] != b[i][j])ok=0;
			}
		}
		if(ok){
			cout<<90<<endl;
			continue;
		}

		ok = 1;
		for(int i=n-1,t1=0;i>=0;i--,t1++){
			for(int j=n-1,t2=0;j>=0;j--,t2++){
				if(a[t1][t2] != b[i][j])ok=0;
			}
		}
		if(ok){
			cout<<180<<endl;
			continue;
		}
		/*
		2
		1 2
		3 4
		2 4
		1 3
		*/
		ok = 1;
		for(int i=0,t1=0;i<n;i++,t1++){
			for(int j=n-1,t2=0;j>=0;j--,t2++){
				if(a[t1][t2] != b[j][i])ok=0;
			}
		}
		if(ok){
			cout<<270<<endl;
			continue;
		}
		cout<<-1<<endl;

	}
	return 0;
}
