#include<bits/stdc++.h>
using namespace std;

int a[550];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin>>n>>k;

	int count = 0;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	if(n == 1){
		cout<<0<<endl;
		cout<<a[0]<<endl;
	}
	else{
		for(int i=1;i<n;i++){
			if(a[i-1]+a[i] < k){
				count += k-(a[i]+a[i-1]);
				a[i] += k-(a[i]+a[i-1]);
			}
		}
		cout<<count<<endl;
		for(int i=0;i<n;i++){
			if(i==0){
				cout<<a[i];
			}
			else{
				cout<<' '<<a[i];
			}
		}
		cout<<endl;
	}

	return 0;
}
