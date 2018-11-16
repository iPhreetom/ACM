// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	if(n % 2 == 0){
		cout<<n/2<<endl;
	}
	else{
		//
		bool findit = 0;
		for(int i=2;i<=sqrt(n);i++){
			if(n % i == 0){
				n -= i;
				findit = 1;
				break;
			}
		}
		if(!findit){
			cout<<1<<endl;
		}
		else{
			cout<<n/2+1<<endl;
		}
	}
	return 0;
}
