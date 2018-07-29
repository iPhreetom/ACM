#include<bits/stdc++.h>
using namespace std;

int n,a[100005];
int ans[100005];

int main(){
	ios::sync_with_stdio(false);

	for(int i=2;i<=100001;i++){
		if(a[i] == 0){
			for(int j=i+i;j<=100001;j+=i){
				a[j] = 1;
			}
		}
	}

	cin>>n;
	if(n>2){
		cout<<2<<endl;
		for(int i=2;i<=n+1;i++){
			if(i == 2){
				if(a[i] == 0)cout<<1;
				else cout<<2;
			}
			else{
				if(a[i] == 0)cout<<' '<<1;
				else cout<<' '<<2;
			}
		}
		cout<<endl;
	}
	else{
		if(n == 2){
			cout<<1<<endl;
			cout<<"1 1"<<endl;
		}
		else{
			cout<<1<<endl;
			cout<<1<<endl;
		}
	}


	return 0;
}
