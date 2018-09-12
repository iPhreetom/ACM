// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
using namespace std;

int a[1005];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		for (int i=0; i<n; i++){
			cin>>a[i];
		}
		int ans = 0;
		for(int i=0;i<n;i++){
			for (int j=i+1; j<n; j++){
			    for(int k=j+1;k<n;k++){
					ans = max(ans,(a[i]+a[j])^a[k]);
					ans = max(ans,(a[k]+a[j])^a[i]);
					ans = max(ans,(a[i]+a[k])^a[j]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
