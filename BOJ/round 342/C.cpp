#include<iostream>
using namespace std;

int n,k;
int mp[505][505];

void solve(){

	int ans  = 0;
	int mx = n*n;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=k;j--){
			mp[i][j] = mx--;
			if(j == k)ans += mx+1;
		}
	}

	int mn = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<k;j++){
			mp[i][j] = mn++;
		}
	}

	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<mp[i][j];
			if(j != n)cout<<' ';
		}
		cout<<endl;
	}
}

int main(){
	cin>>n>>k;
	solve();
	return 0;
}
