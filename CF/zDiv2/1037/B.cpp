// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> a;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,s;
	cin>>n>>s;
	for (int i=0; i<n; i++){
	    int t;
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	// for (int i=0; i<a.size(); i++){
	// 	cout<<a[i]<<' ';
	// }cout<<endl;

	int mid = n/2;
	int ans = 0;

	if(a[mid] == s){
		// cout<<0<<endl;
	}
	else if(a[mid] < s){
		for(int i = mid;i<n;i++){
			if(a[i] < s){
				ans += s - a[i];
				a[i] = s;
			}
		}
	}
	else { // a[mid] > s
		for(int i = 0;i<=mid;i++){
			if(a[i] > s){
				ans += a[i] - s;
				a[i] = s;
			}
		}
	}
	// for (int i=0; i<a.size(); i++){
	//     cout<<a[i]<<' ';
	// }cout<<endl;
	cout<<ans<<endl;
	return 0;
}
