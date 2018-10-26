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
	for (int i=1; i<=n/2; i++){
		for (int j=1; j<=n/2+1-i; j++){
			cout<<'*';
		}
		for (int j=1; j<=2*i-1; j++){
			cout<<'D';
		}
		for (int j=1; j<=n/2+1-i; j++){
			cout<<'*';
		}
		cout<<endl;
	}
	for (int i=1; i<=n; i++){
		cout<<'D';
	}
	cout<<endl;

	for (int i=n/2; i>=1; i--){
		for (int j=1; j<=n/2+1-i; j++){
			cout<<'*';
		}
		for (int j=1; j<=2*i-1; j++){
			cout<<'D';
		}
		for (int j=1; j<=n/2+1-i; j++){
			cout<<'*';
		}
		cout<<endl;
	}
	return 0;
}
