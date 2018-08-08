#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int arr[2123456];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		if(n == 0)break;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			if(i!=n-1)cout<<arr[i]<<' ';
			else cout<<arr[i]<<endl;
		}
	}
	return 0;
}
