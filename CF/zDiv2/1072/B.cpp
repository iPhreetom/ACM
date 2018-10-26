// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int a[212345];
int b[212345];
int t[212345];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	for (int i=1; i<=n-1; i++){
		cin>>a[i];
	}
	for (int i=1; i<=n-1; i++){
		cin>>b[i];
	}
	bool ok  = 0;

	for(t[n]=0;t[n]<4;t[n]++){
		bool can = 1;

		for (int i=n-1; i>=1; i--){
			for (int j=0; j<4; j++){
				t[i] = j;
				if(((t[i]|t[i+1]) == a[i]) && ((t[i]&t[i+1]) == b[i])){
					break;
				}
				if(j == 3){
					can = 0;
				}
			}
		}
		if(can){
			ok = 1;
			break;
		}
	}
	// 0 1 10 11
	if(ok){
		cout<<"YES"<<endl;
		for (int i=1; i<=n; i++){
			cout<<t[i]<<' ';
		}
		cout<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

	return 0;
}
