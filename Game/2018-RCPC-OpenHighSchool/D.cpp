#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],vis[maxn],ans[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(m==(n*(n-1)/2))
	{
		cout<<"NO\n";
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		cin>>a[i]>>b[i];
		vis[a[i]]++;
		vis[b[i]]++;
	}
	int mk1=0,mk2=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]<n-1)
		{
			if(mk1)
			{
				mk2=i;
				break;
			}
			else mk1=i;
		}
	}
	int p=3;
	for(int i=1;i<=n;i++)
	{
		if(i == mk1)ans[i]=1;
		else if(i == mk2)ans[i]=2;
		else ans[i]=p,p++;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	cout<<"\n";
	ans[mk2]=1;
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
