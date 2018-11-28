// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int ans = 0;
	for (int i=1; i<=m; i++){
		for (int j=1; j<=m; j++){

			int res = n%m;
			int re = n/m;
			int num1 = re + (res>=i?1:0);
			int num2 = re + (res>=j?1:0);
			if((i*i+j*j)%m == 0){
				ans += num1*num2;
			}

		}
	}
	cout<<ans<<endl;
	return 0;
}
