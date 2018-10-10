// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


list<int> que;
int n;

void solve(){
	bool first = 1;
	int tp = 1;
	int f = n;
	int mx = n;
	while(n){
		if(n == 3){
			cout<<' '<<tp<<' '<<tp<<' '<<mx<<endl;
			break;
		}
		else{
			for (int i=0; i<(n+1)/2; i++){
				if(first)cout<<tp;
				else cout<<' '<<tp;
				first = 0;

			}
		}
		if(n%2){
			mx -= tp;
		}


		n/=2;
		tp*=2;
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	if(n == 3){
		cout<<"1 1 3"<<endl;
	}
	else if(n == 2){
		cout<<"1 2"<<endl;
	}
	else if(n == 1){
		cout<<"1"<<endl;
	}
	else{
		solve();
	}
	return 0;
}
