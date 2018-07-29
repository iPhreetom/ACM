#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	double a[5005];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	double ans = 0 ;

	for(int i=k;i<=n;i++){

		double tp = 0;
		for(int j=0;j<i;j++){
			tp += a[j];
		}

		ans = max(tp/i,ans);
		int index = 0;

		for(int j=i;j<n;j++){
			tp -= a[index++];
			tp += a[j];
			ans = max(tp/i,ans);
		}
	}
	// cout<<ans<<endl;
	printf("%.8f\n",ans);
	return 0;
}
