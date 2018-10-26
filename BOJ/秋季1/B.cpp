// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		a[i+n] = a[i];
	}


	for (int i=1; i<=n; i++){
		bool can = 1;
		for(int j=i+1;j<=i+n-1;j++){
			// cout<<"a[j] = "<<a[j]<<endl;
			// cout<<"a[j-1] = "<<a[j-1]<<endl;
			if(a[j] < a[j-1]){
				can = 0;
				break;
			}
		}

		if(can){
			cout<<i-1<<endl;
			break;
		}
		if(i == n){
			cout<<-1<<endl;
			break;
		}
		// cout<<"i = "<<i<<endl;
	}


	return 0;
}
