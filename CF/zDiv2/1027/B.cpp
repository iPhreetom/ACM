#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	if(n % 2 == 1){
		for (int i=0; i<q; i++){
		    int x,y;
			cin>>x>>y;
			int num = (x-1)*n+y;
			if(num % 2 == 1){
				cout<<(num+1)/2<<endl;
			}
			else{
				int half = (n*n+1)/2;
				cout<<half+(num/2)<<endl;
			}
		}
	}
	else{
		for (int i=0; i<q; i++){
	    	int x,y;
			cin>>x>>y;
			int num = (x-1)*n+y;
			if((x % 2 == 1 && y % 2 == 1) || (x % 2 == 0 && y % 2 == 0)){
				cout<<(x-1)*n/2 + (y+1)/2<<endl;
			}
			else{
				cout<<(x-1)*n/2 + (y+1)/2 + (n*n/2)<<endl;
			}
		}
	}
	return 0;
}
