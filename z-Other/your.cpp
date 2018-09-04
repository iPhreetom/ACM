// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int maxn=15,maxs=(1<<15),inf=(1ll<<60);
int g[maxn+5][maxn+5],dp[maxs+5];bool vis[maxn];
// bitset<20> b;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>g[i][j];
		}
	}
	/*for(int s=1;s<(1<<(n-1));s++)
		dp[s*2]=inf;
	vis[1]=1;
	for(int s=2;s<(1<<n);s++)
	{
		if(s%2==0)continue;
		for(int i=1;i<n;i++)
		{
			if((s&(1<<i))&&vis[s^(1<<i)])
			{
				int minr=inf;
				for(int j=0;j<n;j++)
				{
					if((i!=j)&&(s&(1<<i))&&vis[s^(1<<i)])
					{
						minr=min(g[j][i],minr);
					}
				}
				dp[s]=min(dp[s],dp[s^(1<<i)]+minr);
			}
		}
	}*/
	for(int i=1;i<(1<<(n-1));i++)dp[i]=inf;
	vis[0]=1;
	for(int s=1;s<(1<<(n-1));s++)
	{
		for(int j=1;j<n;j++)
		{
			if((s&(1<<(j-1)))&&(vis[s^(1<<(j-1))]))
			{
				// if()
			}
		}
	}
	cout<<dp[(1<<(n-1))-1]<<endl;
	return 0;
}
