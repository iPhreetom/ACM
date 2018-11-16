// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];
int b[212345];


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	for (int i=1; i<=n; i++){
	    cin>>b[i];
	}

	bool can = 0;
	if(a[1] == 0){
		cout<<"NO"<<endl;
		return 0;
	}
	if(a[m] == 1){
		cout<<"YES"<<endl;
		return 0;
	}

	if(b[m] == 0){
		cout<<"NO"<<endl;
		return 0;
	}

	for (int i=1; i<=n; i++){
		if(i > m && a[i] == 1 && b[i] == 1){
			can = 1;
			break;
		}
	}
	if(can)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
