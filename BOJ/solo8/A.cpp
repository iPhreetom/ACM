#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	string a[101];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int g[101];
	int ok = -1;
	for(int i=0;i<n;i++){
		cin>>g[i];
		if(g[i] == 0){
			ok = i+1;
		}
	}
	if(ok == -1){
		cout<<0<<endl;
	}
	else{
		cout<<ok<<endl;
	}
	return 0;
}
