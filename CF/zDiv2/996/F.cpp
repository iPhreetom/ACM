// CF 996 F
	// 总结
		// 输出请使用 %f

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,r,len;
long double a[1<<18+5];
long double ans ;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);


	cin>>n>>r;

	len = pow(2,n);
	for(int i=0;i<len;i++){
		cin>>a[i];
		ans += a[i];
		// cout<<"---"<<ans<<endl;
	}
	// cout<<ans/len<<endl;
	printf("%.9f\n",ans/len);
	for(int i=0;i<r;i++){
		int t,g;
		cin>>t>>g;
		ans -= a[t];
		ans += g;
		a[t] = g;
		printf("%.9f\n",ans/len);
		// cout<<ans/len<<endl;
	}

	return 0;
}
