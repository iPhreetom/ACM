#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	vector<int> arr;

	int mx = 0;
	for (int i=0; i<n; i++){
	    int t;
		cin>>t;
		arr.push_back(t);
		if(i != 0){
			mx = max(arr[i]-arr[i-1],mx);
		}
	}

	mx = 1e17;
	for (int i=1; i<n-1; i++){
		int nowmx = 0;
		for(int j=1;j<n;j++){
			if(j != i && j-1 != i){
				nowmx = max(nowmx,arr[j]-arr[j-1]);
			}
			else{
				if(j-1 == i){
					nowmx = max(nowmx,arr[j]-arr[j-2]);
				}
			}
		}
		mx = min(mx,nowmx);
	}
	cout<<mx<<endl;

	return 0;
}
