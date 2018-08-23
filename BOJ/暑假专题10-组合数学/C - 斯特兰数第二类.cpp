#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 20090126;
int ans[1004];
int num[105][105];
int f[105];

void solve(){
	int n;
	cin>>n;
	int out = 0;
	for (int i=1; i<=n; i++){
		out += f[i]*num[n][i]%mod;
		out %= mod;
	}
	cout<<out<<endl;
}


int stirling(int n,int m){
	if(num[n][m])return num[n][m];

	if(n == m){
		return num[n][m] = 1;
	}
	if(m == 1){
		return num[n][m] = 1;
	}
	return num[n][m] = (m*stirling(n-1,m)%mod+stirling(n-1,m-1)%mod)%mod;
}

void init(){
	f[1]=1;
	for (int i=2;i<=100; i++){
	    f[i] = f[i-1]*i%mod;
	}
	for (int i=1; i<=100; i++){
	     for (int j=1; j<=i; j++){
			 stirling(i,j);
	     }
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init();
	// cout<<(NULL==NULL)<<'1'<<endl;
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
