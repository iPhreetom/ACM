#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[1002];
int ans = 0;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		ll t;
		cin>>t;
		a[t]++;
		ans = max(ans,a[t]);
	}
	cout<<ans<<endl;
	return 0;
}
