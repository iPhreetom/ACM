// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int a[2123];
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	cout<<n+1<<endl;
	int index = 0;
	for (int i=n; i>=1; i--){
		++index;
		int res = (n-index);
		int now = a[i]%n;
		int fix = 0;
		if(res > now){
			fix = res-now;
		}
		else{
			fix = n+res-now;
		}
		cout<<1<<' '<<i<<' '<<fix<<endl;
		for (int j=1; j<=n; j++){
			a[j] += fix;
		}
	}
	cout<<2<<' '<<n<<' '<<(n)<<endl;

	return 0;
}
