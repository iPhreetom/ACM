#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


map<int,int> mpa;
map<int,int> mpb;
int arr[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,x;
	cin>>n>>x;


	int st = 0;

	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(mpa.count(arr[i]) != 0){
			st = 1;
		}
		mpa[arr[i]]++;
	}

	if(st == 1){
		cout<<0<<endl;
		return 0;
	}

	bool th = 0;
	for(int i=0;i<n;i++){
		if((arr[i]&x) == arr[i]){
			if(mpa[arr[i]] >= 2){
				st = 2;
			}
		}
		else if(mpa.count((arr[i]&x)) != 0){
			st = 2;
		}
		if(mpb.count((arr[i]&x)) != 0)th = 1;

		mpb[(arr[i]&x)]++;
	}
	if(st == 2){
		cout<<1<<endl;
	}else if(th){
		cout<<2<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
}
