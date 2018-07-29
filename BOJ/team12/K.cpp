#include<bits/stdc++.h>
using namespace std;

int n;
int a[112345];
int book[112345];
int mx[112345];
int ans[312345];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);


	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		book[a[i]]++;
	}
	int tp = n;
	mx[1] = n;
	for(int i=2;i<=n;i++){
		tp -= book[i-1];
		mx[i] = tp;
	}

	for(int i=1;i<=n;i++){
		ans[i] = mx[a[i]]--;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}
