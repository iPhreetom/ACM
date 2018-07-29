#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10+5;
int a[maxn][maxn],da[]={1,0,-1,0},db[]={0,-1,0,1};//direction
bool vis[maxn][maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int curpa=1,curpb=n,cur=0;//current position
	a[1][n]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			vis[i][j]=1;
		}
	}
	for(int i=2;i<=n*n;i++)
	{
		vis[curpa][curpb]=0;
		if(!vis[curpa+da[cur]][curpb+db[cur]])
		{
			cur++;
			cur%=4;
		}
		//cout<<cur<<endl;
		curpa+=da[cur];
		curpb+=db[cur];
		a[curpa][curpb]=i;


	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
