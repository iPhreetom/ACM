// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;

	if(n > 2*m){
		cout<<n - 2*m<<' ';
	}
	else{
		cout<<0<<' ';
	}

	int d = 0;
	for (int i=1; i<=n; i++){
		if( i*(i-1)/2 >= m){
			d = i;
			break;
		}
	}

	if(n == 1)d = 1;
	if(m == 0)d = 0;
	cout<<n-d<<endl;

	return 0;
}
