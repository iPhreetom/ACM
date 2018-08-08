#include<bits/stdc++.h>
using namespace std;

int a[112345];
int b[112345];
int need[112345];
bool book[112345];

int n,m;

bool check(int n){
	memset(book,0,sizeof(book));
	int rest = 0;
	for(int i=n-1;i>=0;i--){
		b[i] = a[i];
		if(book[b[i]] == 0)book[b[i]] = 1;
		else b[i] = 0;
	}
	for(int i=1;i<=m;i++){
		if(book[i] == 0){
			return false;
		}
	}
	for(int i=0;i<n;i++){
		if(b[i] == 0){
			rest++;
		}
		else{
			rest -= need[b[i]];
			if(rest < 0)return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>need[i];
	}
	int l=0,r=n;

	while(l+1<r){
		int mid = l + (r-l)/2;
		if(check(mid))r = mid;
		else l = mid;
	}
	if(check(l)){
		cout<<l<<endl;
	}
	else{
		if(check(r)){
			cout<<r<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
