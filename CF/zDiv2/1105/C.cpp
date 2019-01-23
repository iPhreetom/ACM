#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int a[212345][3];
const int mod = 1e9 + 7;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,l,r;
	cin>>n>>l>>r;

	while(l%3 != ((r%3)+1)%3 && l <= r) {
		a[1][l%3] ++ ;
		l++;
	}

	a[1][0] += (r+1-l)/3;
	a[1][1] += (r+1-l)/3;
	a[1][2] += (r+1-l)/3;
	int zero = a[1][0];
	int one = a[1][1];
	int two = a[1][2];

	for (int i=2; i<=n; i++){
		a[i][0] = (a[i-1][0]*zero)%mod + (a[i-1][2]*one)%mod + (a[i-1][1]*two)%mod;
		a[i][0] %= mod;
		a[i][1] = (a[i-1][1]*zero)%mod + (a[i-1][2]*two)%mod + (a[i-1][0]*one)%mod;
		a[i][1] %= mod;
		a[i][2] = (a[i-1][0]*two)%mod + (a[i-1][2]*zero)%mod + (a[i-1][1]*one)%mod;
		a[i][2] %= mod;
	}
	cout<<a[n][0]<<endl;
	return 0;
}
