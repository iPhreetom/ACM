// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int maxn=1e4+5,maxk=1e3+5;
int a[maxn],vis[maxk];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k,ans;bool f=1,f1=1;
	cin>>k>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		vis[a[i]]++;
	}
	//+
	ans=0;
	f1=1;
	if((n+1)%k==0)
	{
		for(int i=1;i<=k;i++)
		{
			if(vis[i]==(n+1)/k-1&&ans==0)ans=i;
			else if(vis[i]!=(n+1)/k)
			{
				f1=0;break;
			}
		}
		if(f1&&ans)
		{
			cout<<"+"<<ans<<endl;
			f=0;
			return 0;
		}
	}
	//-
	ans=0;
	f1=1;
	if((n-1)%k==0&&f)
	{
		for(int i=1;i<=k;i++)
		{
			if(vis[i]==(n-1)/k+1&&ans==0)ans=i;
			else if(vis[i]!=(n-1)/k)
			{
				f1=0;break;
			}
		}
		if(f1&&ans)
		{
			cout<<"-"<<ans<<endl;
			f=0;
			return 0;
		}
	}
	//+-
	ans=0;
	int ans1=0;
	f1=1;
	if(n%k==0&&f)
	{
		for(int i=1;i<=k;i++)
		{
			if(vis[i]==n/k+1&&ans==0)ans=i;
			else if(vis[i]==n/k-1&&ans1==0)ans1=i;
			else if(vis[i]!=n/k)
			{
				f1=0;break;
			}
		}
		if(f1&&ans&&ans1)
		{
			cout<<"-"<<ans<<" +"<<ans1<<endl;
			f=0;
			return 0;
		}
	}
	if(f)cout<<"*\n";
	return 0;
}
