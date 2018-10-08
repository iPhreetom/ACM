// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[11234];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		memset(a,0,sizeof(a));
		cin>>n;
		for (int i=0; i<n; i++){
			int tp;
			cin>>tp;
			a[tp]++;
		}
		int sum = 0;
		for (int i=1; i<11234; i++){
			sum = max(sum,a[i]+a[i-1]);
		}
		cout<<sum<<endl;
	}
	return 0;
}
