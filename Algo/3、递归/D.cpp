#include<bits/stdc++.h>
using namespace std;

long long ans = 0;
unsigned long long dp[12345];

long long hanoi(long long n)
{
	if(dp[n] != 0){
		ans += dp[n];
		return dp[n];
	}
	if(n>=2)
	{
		dp[n] += hanoi(n-1);
		ans += dp[n];
		dp[n] += hanoi(n-1);
		return dp[n];
	}
	else if(n==1){
		ans+=2;
		return dp[n] = 2;
	}
}


int main()
{
	long long x;
	cin>>x;
	hanoi(x);

	cout<<ans<<endl;
}
