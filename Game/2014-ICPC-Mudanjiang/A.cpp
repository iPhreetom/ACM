// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;

		int sum1 = 0,sum2 = 0;

		for (int i=0; i<n-1; i++){
			int tp;cin>>tp;
			sum2 += tp;
		}

		for (int i=0; i<m; i++){
			int tp;cin>>tp;
			sum1 += tp;
		}

		sum2 = (sum2-1)/(n-1);

		sum1 /= m;
		sum1 ++;

		cout<<sum1<<' '<<sum2<<endl;
	}
	return 0;
}
