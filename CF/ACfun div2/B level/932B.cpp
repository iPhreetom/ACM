// fyt

// 前缀和
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int dp[(int)1e6+10][10];
int num[(int)1e6+10];

int f(int n){
	int sum = 1;
	while(n){
		int q = n%10;
		if(q != 0){
			sum *= q;
		}
		n /= 10;
	}
	return sum;
}

int init(){
	for (int i=1; i<10; i++){
		dp[i][i] = 1;
		num[i] = i;
	}

	for (int i=1; i<=1e6+1; i++){
		int t = num[f(i)];
		num[i] = t;
		dp[i][t]=1;
	}

	for (int i=1; i<=1e6+1; i++){
		for (int j=0; j<10; j++){
			dp[i][j] += dp[i-1][j];
		}
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init();
	int q;
	cin>>q;
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		cout<<dp[r][k]-dp[l-1][k]<<endl;
	}
	return 0;
}
