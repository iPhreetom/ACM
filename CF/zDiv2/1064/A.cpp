// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	vector<int> a;
	for (int i=0; i<3; i++){
	    int t;
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	int ans = 0;
	while(a[1] + a[0] <= a[2]){
		if(ans%2 == 0){
			a[0] ++;
			ans++;
		}
		else{
			a[1] ++;
			ans++;
		}
		sort(a.begin(),a.end());
	}
	cout<<ans<<endl;
	return 0;
}
