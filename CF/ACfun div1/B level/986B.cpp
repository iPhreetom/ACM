#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int n;
int a[2123456];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	int ans = 0;
	for(int i=1;i<=n;i++){
		while(a[i] != i){
			swap(a[a[i]],a[i]);
			ans++;
		}
		// cout<<a[i]<<' ';
	}
	
	if(n % 2 == 1){
		if(ans % 2 == 1)cout<<"Petr"<<endl;
		else cout<<"Um_nik"<<endl;
	}
	else{
		if(ans % 2 == 0)cout<<"Petr"<<endl;
		else cout<<"Um_nik"<<endl;
	}
	return 0;
}
