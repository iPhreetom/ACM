#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> arr;
int ans[112345];
int b[112345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
// 1 1 1 1 0 1 0 1 1 0 0 0 0 0

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		arr.push_back(t);
	}


	for(int i=0;i<n;i++){
		int index = arr[i];
		int j=0;
		for(;index;j++){
			if(b[j] == 0){
				b[j] = 1;
				index--;
			}else if(b[j] == 2){

			}else if(b[j] == 1){
				index--;
			}
		}
		b[j] = 2;
	}

	for(int i=0;i<2*n;i++){
		cout<<b[i]<<' ';
	}


	return 0;
}
