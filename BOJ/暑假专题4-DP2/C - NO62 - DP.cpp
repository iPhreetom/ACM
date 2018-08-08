// hdu2089

#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int dp[10][10];
int n,m;

void init2()
{
    dp[0][0] = 1;
    for (int i = 1; i <= 7; ++i)
        for (int j = 0; j <= 9; ++j)
            for (int k = 0; k <= 9; ++k)
                if (j != 4 && !(j == 6 && k == 2))
                    dp[i][j] += dp[i - 1][k];
	// for(int i=0;i<10;i++){
	// 	for(int j=0;j<10;j++){
	// 		cout<<dp[i][j]<<' ';
	// 	}cout<<endl;
	// }
}

void init(){
	// define dp[i][j] or dp[i][k]
	// memset(dp,0,sizeof(dp));
	// for (int i=0; i<=9; i++){
	//     if(i == 4)continue;
	// 	dp[1][i]=2;
	// }
	dp[0][0]=1;
	for(int i=1;i<=7;i++){
		for(int j=0;j<=9;j++){
			if(j == 4)continue;
			for(int k=0;k<=9;k++){
				if(k == 4)continue;
				if(k == 2 && j == 6)continue;
				dp[i][j] += dp[i-1][k];
			}
		}
	}
	// for(int i=0;i<10;i++){
	// 	for(int j=0;j<10;j++){
	// 		cout<<dp[i][j]<<' ';
	// 	}cout<<endl;
	// }
}

int solve2(int n)
{
	int d[20];
    int ans = 0;
    int len = 0;
    while (n) {
        ++len;
        d[len] = n % 10;
        n /= 10;
    }
    d[len + 1] = 0;
    for (int i = len; i >= 1; --i) {
        for (int j = 0; j < d[i]; ++j) {
            if (d[i + 1] != 6 || j != 2)
                ans += dp[i][j];
        }
        if (d[i] == 4 || (d[i + 1] == 6 && d[i] == 2))
            break;
    }
    return ans;
}

int solve(int x){
	int d[20];
	int len = 0;
	while(x){
		len++;
		d[len] = x%10;
		x /= 10;
	}
	d[len+1]=0;

	int ans = 0;
	for(int i=len;i>=1;i--){
		for(int j=0;j<d[i];j++){
			if(j == 4 || (j==2 && d[i+1]==6))continue;
			ans += dp[i][j];
		}

		if(d[i] == 4 || (d[i] == 2 && d[i+1] == 6))break;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// init2();
	init();

	while(cin>>n>>m){
		if(n == 0 && m == 0)break;
		// cout<<"solve(m) = "<<solve(m)<<endl;
		// cout<<"solve(n) = "<<solve(n)<<endl;
		cout<<solve(m+1)-solve(n)<<endl;
	}
	return 0;
}
