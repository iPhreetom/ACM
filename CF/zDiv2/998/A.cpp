#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	int a[1234];
	cin>>n;

	int mn = 100000;
	int index = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i] < mn){
			mn = a[i];
			index = i;
		}
	}

	if(n == 1){
		cout<<-1<<endl;
		return 0;
	}

	if(n == 2){
		if(a[0] == a[1]){
			cout<<-1<<endl;
			return 0;
		}
		else{
			cout<<1<<endl;
			cout<<1<<endl;
			return 0;
		}
	}

	cout<<1<<endl;
	cout<<index+1<<endl;

	return 0;
}
